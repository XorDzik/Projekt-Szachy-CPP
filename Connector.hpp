/*!
* \file
* \brief Ruchy komputera
*
* Plik zawiera zmienne i funkcje odpowiedzialne za wykonywanie ruchow przez komputer.
*
*/

#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>

/*!
* \brief Start up info
* Okresla stacje okna, pulpit, standardowe uchwyty i wyglad glownego okna procesu w czasie tworzenia.
*
*/
STARTUPINFO sti = {0};
/*!
* \brief ochrona atrybutow
*   struktura SECURITY_ATTRIBUTES zawiera deskryptor bezpieczenstwa dla obiektu i okresla, czy uchwyt uzyskany przez okreslenie
*   tej struktury jest dziedziczony. Ta struktura zapewnia ustawienia zabezpieczen dla obiektow utworzonych za pomocą roznych funkcji,
*   takich jak CreateFile, CreatePipe, CreateProcess
*
*/
SECURITY_ATTRIBUTES sats = {0};
/*!
* \brief Process information
*   Zawiera informacje o nowo utworzonym procesie i jego glownym watku.
*
*/
PROCESS_INFORMATION pi = {0};
/*!
* \brief Handle
*   Deklaracja uchwytow do obiektu
*
*/
HANDLE pipin_w, pipin_r, pipout_w, pipout_r;
/*!
* \brief Byte
*   Deklaracja bufora
*
*/
BYTE buffer[2048];
/*!
* \brief Dword
*   Deklaracja zmiennych typu DWORD
*
*/
DWORD writ, excode, read, available;

/*!
** @brief Polacz sie z silnikiem
*   Procedura umozliwia polaczenie sie z silnikiem odpowiedzialnym za generowanie ruchow komputera podczas rozgrywki.
* @param[in] jako parametr pobiera wskaznik typu char
*
*/

void ConnectToEngine(char* path)
{
   pipin_w = pipin_r = pipout_w = pipout_r = NULL;
   sats.nLength = sizeof(sats);
   sats.bInheritHandle = TRUE;
   sats.lpSecurityDescriptor = NULL;

   CreatePipe(&pipout_r, &pipout_w, &sats, 0);
   CreatePipe(&pipin_r, &pipin_w, &sats, 0);

   sti.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
   sti.wShowWindow = SW_HIDE;
   sti.hStdInput = pipin_r;
   sti.hStdOutput = pipout_w;
   sti.hStdError = pipout_w;

   CreateProcess(NULL, path, NULL, NULL, TRUE,0, NULL, NULL, &sti, &pi);
}

/*!
** @brief Pobierz ruch
*   Funkcja sprawdza ruchy ktore moze wykonac komputer.
* @param[in] jako parametr pobiera zmienną typu string
* @return Zwraca najlepszy mozliwy ruch komputera
*
*/

std::string getNextMove(std::string position)
{
	std::string str;
	position = "position startpos moves "+position+"\ngo\n";

	WriteFile(pipin_w, position.c_str(), position.length(),&writ, NULL);
    Sleep(500);

    PeekNamedPipe(pipout_r, buffer,sizeof(buffer), &read, &available, NULL);
    do
    {
        ZeroMemory(buffer, sizeof(buffer));
		if(!ReadFile(pipout_r, buffer, sizeof(buffer), &read, NULL) || !read) break;
        buffer[read] = 0;
		str+=(char*)buffer;
    }
    while(read >= sizeof(buffer));

	int n = str.find("bestmove");
	if (n!=-1) return str.substr(n+9,4);

    return "error";
}

/*!
** @brief Zamknij połączenie
*   Procedura zamyka polaczenie z silnikiem.
*@return Procedura niczego nie zwraca
*
*/
void CloseConnection()
{
	WriteFile(pipin_w, "quit\n", 5,&writ, NULL);
    if(pipin_w != NULL) CloseHandle(pipin_w);
    if(pipin_r != NULL) CloseHandle(pipin_r);
    if(pipout_w != NULL) CloseHandle(pipout_w);
    if(pipout_r != NULL) CloseHandle(pipout_r);
    if(pi.hProcess != NULL) CloseHandle(pi.hProcess);
    if(pi.hThread != NULL) CloseHandle(pi.hThread);
}


#endif CONNECTOR_H

