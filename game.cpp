#include<windows.h>
#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

//DETECTING GRAPHICAL DRIVERS

int gd = DETECT, gm;

//FUNCTIONS

int game();

int new_game();

int cont_game();

int load_game();

int load_file(string loadfil);

int quit();

//INTEGERS

int charx;

int chary;

int progress;

//STRINGS

string scharx;

string schary;

string def_loadfi;

string sprogress;

//ASCII KEY DEFINITIONS

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESCAPE 27

//ARROW SELECTION INTEGER

int pixy = 1;


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
//                  MAIN FUNCTION
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------

int main(){

int tye = 0;

system("cls");

//OPENS GRAPHICAL WINDOW

   initwindow(640,480);
  HWND hWnd, hWndChild;
  hWnd = FindWindow(NULL, "Windows BGI");
  hWndChild = GetWindow(hWnd, GW_CHILD);
  SendMessage((HWND) hWnd, WM_SETTEXT,0, (LPARAM)"TITLE"); //LPARAM IS WINDOW TITLE
   setbkcolor(LIGHTRED);//CHANGE BACKGROUND TO ANY COLOR
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);//CHANGE BACKGROUND TO ANY COLOR
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);//SETS THE TITLES STYLE OF TEXT
   setcolor(BLUE);//CHANGE TITLE TEXT TO ANY COLOR
   outtextxy(10, 30, "MAIN_TITLE");// CHANGE TITLE
   setcolor(CYAN);//SET SELECTION TEXT TO ANY COLOR
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);//SETS THE STYLE OF TEXT FOR THE SELECTION ITEMS
   outtextxy(165, 200, "1  New Game");//SELECTION ITEM 1
   outtextxy(165, 250, "2  Continue Game");//SELECTION ITEM 2
   outtextxy(165, 300, "3  Load Save");//SELECTION ITEM 3
   getch();//CHECKS FOR INPUT
   game();//DECLARES GAME FUNCTION
   cleardevice();//CLEARS GRAPHICAL SCREEN
   closegraph();//CLOSES SCREEN


   return 0;
}


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
//                  GAME FUNCTION
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------


int game(){

   //SHOWS SELECTION MENU

   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "MAIN_TITLE");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  New Game");
   outtextxy(165, 250, "2  Continue Game");
   outtextxy(165, 300, "3  Load Save");



   //DRAWS RECTANGLE AROUND SELECTION
   if(pixy < 1){

    pixy = 3;
    game();

   }
   if(pixy == 2 ){
   cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "MAIN_TITLE");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  New Game");
   outtextxy(165, 250, "2  Continue Game");
   outtextxy(165, 300, "3  Load Save");
   rectangle(150, 240, 190, 280);
   }
   if(pixy == 1 ){
   cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "MAIN_TITLE");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  New Game");
   outtextxy(165, 250, "2  Continue Game");
   outtextxy(165, 300, "3  Load Save");
   rectangle(150, 190, 190, 230);

   }
   if(pixy == 3 ){
   cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "MAIN_TITLE");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  New Game");
   outtextxy(165, 250, "2  Continue Game");
   outtextxy(165, 300, "3  Load Save");
   rectangle(150, 290, 190, 330);

   }
   if(pixy > 3){

    pixy = 1;

    game();

   }

   //GRABS USER INPUT FROM ARROW KEYS

   int c = 0;
    while(1)
    {
        c = 0;

        switch((c=getch())) {
        case KEY_UP:

        //MAKES SQUARE GO UP

        pixy = pixy - 1;

        //DECLARES PARENT FUNCTION

        game();
        break;

        case KEY_DOWN:

        //MAKES SQUARE GO DOWN

        pixy = pixy + 1;

        //DECLARES PARENT FUNCTION

        game();
        break;

        case KEY_ENTER:

        //CHECKS TO SEE IF ENTER KEY IS PRESSED

        if(pixy == 1){

        //IF PRESSED, NEW GAME(new_game) FUNCTION IS DECLARED

        new_game();

        }

        if(pixy == 2){

        //IF PRESSED, CONTINUE GAME(cont_game) FUNCTION IS DECLARED

        cont_game();

        }

        if(pixy == 3){

        //IF PRESSED, LOAD GAME(load_game) FUNCTION IS DECLARED

        load_game();

        }

        break;
        case KEY_ESCAPE:

        //IF PRESSED, QUIT(quit) FUNCTION IS DECLARED

        quit();

        break;

        }
    }

}

//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
//                  NEW GAME FUNCTION
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
int new_game(){

   //SETS DEFAULT VALUES FOR NEW GAME SAVE

   charx = 10; //CHARACTER X VALUE
   chary = 20; //CHARACTER Y VALUE

   progress = 1; //GAME PROGRESS

   //CHECKS IF save1.gtc HAS BEEN CREATED

    ifstream fin("save1.gtc");

    if(fin) {

    //IF save1.gtc HAS BEEN CREATED, save2.gtc GETS CREATED

    ifstream bin("save2.gtc");

        if(bin){
           //IF save2.gtc  HAS BEEN CREATED save3.gtc GETS CREATED
            ofstream savef;
            savef.open ("save3.gtc");
            savef << charx << '\n';
            savef << chary << '\n';
            savef << progress << '\n';
            savef.close();
            cleardevice();
            setbkcolor(LIGHTRED);
            setfillstyle(SOLID_FILL, LIGHTRED);
            floodfill(400,400, LIGHTRED);
            settextstyle(BOLD_FONT, HORIZ_DIR, 4);
            setcolor(BLUE);
            outtextxy(10, 30, "MAIN_TITLE");
            setcolor(CYAN);
            settextstyle(BOLD_FONT, HORIZ_DIR, 3);
            outtextxy(165, 200, "New Game Created");
            getch();
            cleardevice();
            load_game();

        }

        else{

            ofstream savef;
            savef.open ("save2.gtc");
            savef << charx << '\n';
            savef << chary << '\n';
            savef << progress << '\n';
            savef.close();
            cleardevice();
            setbkcolor(LIGHTRED);
            setfillstyle(SOLID_FILL, LIGHTRED);
            floodfill(400,400, LIGHTRED);
            settextstyle(BOLD_FONT, HORIZ_DIR, 4);
            setcolor(BLUE);
            outtextxy(10, 30, "MAIN_TITLE");
            setcolor(CYAN);
            settextstyle(BOLD_FONT, HORIZ_DIR, 3);
            outtextxy(165, 200, "New Game Created");
            getch();
            cleardevice();
            load_game();

        }

    }
    else {

      ofstream savef;
      savef.open ("save1.gtc");
      savef << charx << '\n';
      savef << chary << '\n';
      savef << progress << '\n';
      savef.close();

      ofstream default_load;
      savef.open ("default.gtc");
      savef << "save1.gtc" << '\n';
      savef.close();
      cont_game();
    }


   //SHOWS THAT NEW GAME GETS CREATED

   cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "MAIN_TITLE");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "New Game Created");
   getch();
   cleardevice();
   cont_game();

   return 0;
}


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
//              CONTINUE GAME FUNCTION
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
int cont_game(){



   //CHECKS default.gtc FOR DEFAULT SAVE FILE

   ifstream load_defaults("default.gtc");
   if(load_defaults.is_open()){

   //SETS VALUE OF def_loadfi WITH DEFAULT SAVE FILE

    getline(load_defaults, def_loadfi);

   }

   //CONVERTS STRING TO MUTABLE CHAR

   char * cdef_loadfi = new char[def_loadfi.size() + 1];
    copy(def_loadfi.begin(), def_loadfi.end(), cdef_loadfi);
    cdef_loadfi[def_loadfi.size()] = '\0';

   //LOADS DEFAULT SAVE FILE

   ifstream file(cdef_loadfi);
   if(file.is_open()){

    //ASSIGNS CHARACTER VALUES TO STRINGS

    getline(file, scharx);
    getline(file, schary);
    getline(file, sprogress);

    //CLOSES FILE

    file.close();

    //CONVERTS CHARACTER VALUES TO INTEGERS

    stringstream charxst(scharx);

    charxst >> charx;

    stringstream charyst(schary);

    charyst >> chary;

    stringstream progressst(sprogress);

    progressst >> progress;

    //CONVERSIONS OF CHARACTER VALUES TO MUTABLE CHARS

    char * cccharx = new char[scharx.size() + 1];
    copy(scharx.begin(), scharx.end(), cccharx);
    cccharx[scharx.size()] = '\0';

    char * ccchary = new char[schary.size() + 1];
    copy(schary.begin(), schary.end(), ccchary);
    ccchary[schary.size()] = '\0';

    char * ccprog = new char[sprogress.size() + 1];
    copy(sprogress.begin(), sprogress.end(), ccprog);
    ccprog[sprogress.size()] = '\0';

   //PRINTS LOADED CHARACTER VALUES TO GRAPHICAL INTERFACE

    cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "MAIN_TITLE");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, cccharx);
   outtextxy(165, 220, ccchary);
   outtextxy(165, 240, ccprog);
   getch();
   cleardevice();
   closegraph();

   }
   else {

   //IF SAVE IS NOT LOADED, NEW GAME(new_game) FUNCTION

   new_game();

   }
return 0;
}


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
//                 LOAD GAME FUNCTION
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
int load_game(){

   //SHOWS LOAD FILE SELECTION MENU

   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "Select Load File");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  Save 1");
   outtextxy(165, 250, "2  Save 2");
   outtextxy(165, 300, "3  Save 3");


   if(pixy < 1){

    pixy = 3;
    load_game();

   }
   if(pixy == 2 ){
   cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "Select Load File");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  Save 1");
   outtextxy(165, 250, "2  Save 2");
   outtextxy(165, 300, "3  Save 3");
   rectangle(150, 240, 190, 280);
   }
   if(pixy == 1 ){
   cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "Select Load File");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  Save 1");
   outtextxy(165, 250, "2  Save 2");
   outtextxy(165, 300, "3  Save 3");
   rectangle(150, 190, 190, 230);

   }
   if(pixy == 3 ){
   cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "Select Load File");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  Save 1");
   outtextxy(165, 250, "2  Save 2");
   outtextxy(165, 300, "3  Save 3");
   rectangle(150, 290, 190, 330);

   }


   if(pixy > 3){

    pixy = 1;

    load_game();

   }

   int c = 0;
    while(1)
    {
        c = 0;

        switch((c=getch())) {
        case KEY_UP:

        pixy = pixy - 1;

        load_game();
        break;

        case KEY_DOWN:

        pixy = pixy + 1;

        load_game();
        break;

        case KEY_ENTER:

        if(pixy == 1){

        //DECLARES LOAD FILE(load_file) FUNCTION WITH SAVE FILE NAME

        load_file("save1.gtc");

        }

        if(pixy == 2){

        //DECLARES LOAD FILE(load_file) FUNCTION WITH SAVE FILE NAME

        load_file("save2.gtc");

        }

        if(pixy == 3){

        //DECLARES LOAD FILE(load_file) FUNCTION WITH SAVE FILE NAME

        load_file("save3.gtc");

        }

        break;
        case KEY_ESCAPE:

        //GOES BACK TO GAME FUNCTION WHEN ESCAPE KEY IS PRESSED

        game();

        break;
        }
    }


return 0;
}


//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
//               LOAD FILE FUNCTION
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
int load_file(string loadfil){


char * cloadfil = new char[loadfil.size() + 1];
    copy(loadfil.begin(), loadfil.end(), cloadfil);
    cloadfil[loadfil.size()] = '\0';

   ifstream file(cloadfil);
   if(file.is_open()){

    getline(file, scharx);
    getline(file, schary);
    getline(file, sprogress);

    file.close();

    stringstream charxst(scharx);

    charxst >> charx;

    stringstream charyst(schary);

    charyst >> chary;

    stringstream progressst(sprogress);

    progressst >> progress;

    char * cccharx = new char[scharx.size() + 1];
    copy(scharx.begin(), scharx.end(), cccharx);
    cccharx[scharx.size()] = '\0';

    char * ccchary = new char[schary.size() + 1];
    copy(schary.begin(), schary.end(), ccchary);
    ccchary[schary.size()] = '\0';

    char * ccprog = new char[sprogress.size() + 1];
    copy(sprogress.begin(), sprogress.end(), ccprog);
    ccprog[sprogress.size()] = '\0';



    ofstream default_load;
    default_load.open ("default.gtc");
    default_load << loadfil << '\n';
    default_load.close();

    cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "MAIN_TITLE");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, cccharx);
   outtextxy(165, 220, ccchary);
   outtextxy(165, 240, ccprog);
   getch();
   cleardevice();
   closegraph();

   return 0;
   }
   else {

   new_game();

   }



   return 0;
   }



//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
//                  QUIT FUNCTION
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
   int quit(){


   //LOADS SELECTION MENU
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "Are you sure you");
   outtextxy(10, 60, "want to quit?");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  Yes");
   outtextxy(165, 250, "2  No");


   if(pixy < 1){

    pixy = 2;
    quit();

   }
   if(pixy == 2 ){
   cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "Are you sure you");
   outtextxy(10, 60, "want to quit?");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  Yes");
   outtextxy(165, 250, "2  No");
   rectangle(150, 240, 190, 280);
   }
   if(pixy == 1 ){
   cleardevice();
   setbkcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   floodfill(400,400, LIGHTRED);
   settextstyle(BOLD_FONT, HORIZ_DIR, 4);
   setcolor(BLUE);
   outtextxy(10, 30, "Are you sure you");
   outtextxy(10, 60, "want to quit?");
   setcolor(CYAN);
   settextstyle(BOLD_FONT, HORIZ_DIR, 3);
   outtextxy(165, 200, "1  Yes");
   outtextxy(165, 250, "2  No");
   rectangle(150, 190, 190, 230);

   }


   if(pixy > 2){

    pixy = 1;

    quit();

   }

   int c = 0;
    while(1)
    {
        c = 0;

        switch((c=getch())) {
        case KEY_UP:

        pixy = pixy - 1;

        quit();
        break;

        case KEY_DOWN:

        pixy = pixy + 1;

        quit();
        break;

        case KEY_ENTER:

        if(pixy == 1){

       closegraph();

        //PROGRAM KILLS ITSELF WHEN YES IS SELECTED AND ENTER IS PRESSED
        system("taskkill /F /T /IM GTC2.exe");

        }

        if(pixy == 2){

        //PROGRAM GOES BACK WHEN NO IS SELECTED AND ENTER IS PRESSED
        game();

        }

        break;

        }
    }


   return 0;
   }
