#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int fila[50], inicio = 0, fim = -1;
int largura = 20, altura = 20;
int x,y, gameOver, pointX, pointY, flag, continuidade, tamanho;
int const tam = 100;

int tailX[50], tailY[50];


void update();
void draw();
void setup();
void input();

void fila_construtor(int fila[50], int inicio, int *fim, int tailX){
	*fim = *fim++;
	
}

int main(){
    
	
	tamanho = 0;
    setup();
    while(gameOver == 0){
        //velocidade da cobra
        Sleep(150);
        
		draw();
        input();
        update();
        printf("Score: %d", tamanho);
    }

    printf("\n\n Fim de Jogo!");
    getch();
    return 0;
}

void draw(){
    system("cls");
int i, j, k;
    
	for (i = 0; i < altura; i++){

            for(j = 0; j < largura; j++)
            {
                //aumento da cobra
                if(x==pointX && y==pointY)
                {
                    
					tamanho++;
                    label3:
                    pointX = rand() % 18;
                    if(pointX == 0)
                    {
                    goto label3;
                    }

                    label4:
                    pointY = rand() % 18;
                    if(pointY == 0)
                    {
                        goto label4;
                    }
                }

                if(i == 0 || i == altura - 1 || j==0 || j == largura - 1)
                {
                    //parede do jogo
                    printf("%c", 600);
                }else{
                    int ch=0;
                    if(pointX==i && pointY==j)
                        printf("%c", 1);

                    else if(x==i && y==j)
                        printf("%c", 2000);
                	//area do jogo
                	else
                    {

                        for( k=0; k<tamanho; k++)
                        {
                            if(i == tailX[k] && j == tailY[k])
                            {
                    
								printf("%c", 1200);
                                ch=1;
                            }
                        }
                        if(ch==0)
                            printf(" ");
                }
            }
            }
            printf("\n");
    if(i == j){
    	gameOver = 1;
	}
	
	}


}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
void setup(){
    gameOver = 0;
    x = largura/2;
    y = altura/2;


label1:
    pointX = rand() % altura;
    if(pointX == 0)
        {
            goto label1;
        }

label2:
    pointY = rand() % largura;
    if(pointY == 0)
        {
            goto label2;
        }
}
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
void update()
{
    int k;
	int vetPrevX = tailX[0];
    int vetPrevY = tailY[0];

    int vet2PrevX, vet2PrevY;

    tailX[0] = x;
    tailY[0] = y;

    for(k = 1; k < tamanho; k++)
    {
        vet2PrevX = tailX[k];
        vet2PrevY = tailY[k];
        tailX[k] = vetPrevX;
        tailY[k] = vetPrevY;
        vetPrevX = vet2PrevX;
        vetPrevY = vet2PrevY;
    }

   switch(flag)
   {
    case 1:

        x--;
        break;
    case 2:
        x++;
        break;

   case 3:
        y--;
        break;

   case 4:
        y++;
        break;
   }
   //Fim de jogo
   if((x==0)||(y==0)||(y==altura-1)||(x==largura-1) || ((pointX == vetPrevX) && (pointY == vetPrevY) ))
        gameOver = 1;

}
//-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------
void input()
{
    continuidade = 0;
    if(kbhit()){
       switch(getch())
       {
       case'w':
           if(flag==2)
                continuidade = 1;

           if(continuidade==0)
            flag = 1;

            break;

        case's':
            if(flag==1)
                continuidade = 1;

           if(continuidade==0)
                flag = 2;
            break;

        case'a':
            if(flag==4)
                continuidade = 1;

           if(continuidade==0)
                flag = 3;
            break;

        case'd':
            if(flag==3)
                continuidade = 1;

           if(continuidade==0)
                flag = 4;
            break;

       case 'x':
            //sair
            gameOver=1;
            break;

       }



    }
}
// ==================================================================================================================
int start, end;
int tila[50];

// ---------------------------------------------------
void fila_construct (){
	start = 0;
	end = -1;	
}
// ----------------------------------------------------
bool fila_vazia(){
	if(start>end){
		return true;
	}
	else{
	return false;	
	} 
}
// ----------------------------------------------------
bool fila_cheia(){
	if(end == tam-1){
		return true;
	}
	else{
		return false;
	}
}
// ----------------------------------------------------
bool fila_enfileirar(int valor){
if(fila_cheia()){
	return false;
} else{
	end++;
	fila[end] = valor;
	return true;
}

}
// ----------------------------------------------------
bool fila_desenfileirar(int &valor){
	if(fila_vazia()){
		return false;
	}
	else{
		valor = fila[start];
		start++;
		return true;
	}
}
// ----------------------------------------------------
bool fila_get(int &valor){
	if (fila_vazia()){
		return false;
	}else{
		valor = fila[start];
		return true;
	}
}
// ----------------------------------------------------
int fila_tamanho(){
	return (end - start) + 1;
}
// ----------------------------------------------------

