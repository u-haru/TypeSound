#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void exitfunc(){
    printf("Exit now...");
    fflush(stdout);
    fflush(stdin);
}
int main()
{
    atexit(exitfunc);
	bool key[46];
	memset(key,0,sizeof(key));
	while (true)
	{
		for (int i = 48; i <= 90; i++) {

			if (GetAsyncKeyState(i) && key[i-48] == FALSE)
			{
				printf("%c",(char)i);
				PlaySound("Sounds/KEYS",0, SND_FILENAME | SND_ASYNC);
				key[i - 48] = TRUE;
			}else if(GetAsyncKeyState(i) == FALSE) key[i - 48] = FALSE;
		}
		if (GetAsyncKeyState(VK_OEM_MINUS) && key[45] == FALSE)
		{
			printf("-");
			PlaySound("Sounds/KEYS.wav", 0, SND_FILENAME | SND_ASYNC);
			key[45] = TRUE;
		}else if(GetAsyncKeyState(VK_OEM_MINUS) == FALSE) key[45] = FALSE;
		if (GetAsyncKeyState(VK_RETURN) && key[43] == FALSE)
		{
			printf("\n");
			PlaySound("Sounds/ENTER.wav", 0, SND_FILENAME | SND_ASYNC);
			key[43] = TRUE;
		}else if (GetAsyncKeyState(VK_RETURN) == 0) key[43] = FALSE;
		if (GetAsyncKeyState(VK_SPACE) && key[44] == FALSE)
		{
			printf(" ");
			PlaySound("Sounds/SPACE.wav", 0, SND_FILENAME | SND_ASYNC);
			key[44] = TRUE;
		}
		else if (GetAsyncKeyState(VK_SPACE) == 0) key[44] = FALSE;
	}
	return 0;
}