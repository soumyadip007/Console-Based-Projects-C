#include <conio.h>    // Clear Screen And getch()
#include <string.h>   // Copy and Compare Strings
#include <stdlib.h>   // Random 
#include <iostream>   // Cout
#include <fstream>    // To handle Highscores 
#include <math.h> 
#include <windows.h> 
using namespace std ;

void gotoxy(int x , int y)
{
    static HANDLE h = NULL ;
    if(!h) h = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD c = { x , y };
    SetConsoleCursorPosition(h,c) ;
}
int random( int AAA ) 
{
    return rand()%AAA ;
}

void cls()
{
     system("cls") ;
}

void CLS()
{
	 gotoxy(0,0) ; 
}

void spaceing(int Space_amount , char C = ' ' )
{
	 for(int i = 0 ; i < Space_amount ; i++) cout << C ;
}

int intlen(int Arg)
{
     int Loop_1 = 0 ; 
     do{ Arg /= 10 ; Loop_1 ++ ; }while( Arg > 0 ) ; 
     return Loop_1 ;
}

void framepause(long double _framepause_ = 20000)
{
	for(long double i = 0 ; i < _framepause_ ; i++)
	for(long double j = 0 ; j < _framepause_ ; j++) ; 
}

float pi = 3.1415926535897932384626433832795028 ; 
float theter = 0 ; 
void circle( int x , int y , float r , char c , float w = 2 , bool out = false ) { 
    for( float theta = 0 ; theta < theter ; theta += 0.03 ) {    
        for( float o = r - w ; o <= r + w ; o += 0.5 ) { 
            gotoxy( cos(theta)*o*1.5 + x , sin(theta)*o + y ) ; 
            if( out and (o == r-w or o == r+w) ) cout << 'x' ; 
            else cout << c ;   
        }
    }
}

class Player 
{
    int  Player_Score    , 
         Player_Goodeats ,
         Player_Rank     ,
         Player_Info     ;
    char Player_Name[10] ;
public :
    Player()
    {
        Player_Rank  = 0 ;
        Player_Score = 0 ;
        Player_Info  = 0 ;
        Player_Goodeats = 0 ;
        strcpy(Player_Name , "") ;
    }
    
    void Get(int e , int ge)
    {
        cout << "Enter Name :>" ;
        gets(Player_Name) ;
        Player_Score = e ;
        Player_Goodeats = ge ; 
    }
    
    void Put()
    {
        cout <<  Player_Rank ;
        if(Player_Rank < 10) cout << " " ;
        cout << " :  | " << Player_Name ;
        spaceing( 15 - strlen(Player_Name) , ' ' ) ;
        cout << "|  " ;
        if(Player_Score < 10) cout << " " ;
        cout << Player_Score << " (" << Player_Goodeats << "%)" ;
    } 
    
    void Set_Rank( int Rank ) { Player_Rank = Rank ; }
    void Set_Info( int Info ) { Player_Info = Info ; }
    char* Name()  { return Player_Name  ; }
    int   Info()  { return Player_Info  ; }
    int   Score() { return Player_Score ; }
    
} PLAYERS[20] ;

struct Ability
{
    char Name[20] , Type[20] ; 
    void (*Execute)() ;
} A[11] ;



void Swap( int     &A , int     &B ){ int     Temp = A ; A = B ; B = Temp ; }
void Swap( Player  &A , Player  &B ){ Player  Temp = A ; A = B ; B = Temp ; }
void Swap( Ability &A , Ability &B ){ Ability Temp = A ; A = B ; B = Temp ; } 

const char    Apple         = 'o' , 
              Orange        = '$' , 
              Start_Head    = '*' ,
              
              Start_Tail    = '+' ,
              Normal_Tail   = ':' ,
			  Special_Tail  = '+' ,
			  
              Start_Wall    = 'X' , 
			  Normal_Wall   = '.' ,
              Special_Wall  = '#' , 
			  
			  Start_Space   = ' ' ,
			  Normal_Space  = ' ' ,
			  Special_Space = 'X' ,
               
			  Up    = 'w' ,
			  Down  = 's' ,
			  Left  = 'a' ,
			  Right = 'd' ,
			  Power = ' ' ,
			  q     = 'q' , 
              CONTROL_KEYS[] = { Up , Left , Down , Right , Power} ,
			  *POINTER       = "\b\b:> " ,
			  *MAIN_MENU_1[] =
									{
										"PLAY"        ,
										"HIGHSCORES"  ,
										"HELP"        ,
										"CONTROLS"    , 
                                        "CREDITS"     ,
										"QUIT"        ,
									}                 , 
			  *MAIN_MENU_2[] =
									{
										"Play "       ,
										"Highscores " ,
										"Help "       ,
										"Controls "   , 
										"Credits "    ,
										"Quit "       ,
									}                 ,
			  *BYE_SCREEN_1[]=
									{
										"I can play a litte more."  ,
										"I have to go."             ,
									}                               ,
			  *BYE_SCREEN_2[]=
									{
										"YES                      " ,
										"NO                       " ,
									}                               ,
               *Halp[] = 
               { 
                       "Classic Nokia Snake game with added things!"                            ,
                       "Blank"                                                                  ,
                       "Abilites are self explainatory as per thier names."                     ,
                       "Of course , Active Abilities are to be activated by power button."      ,
                       "Passive ones are passive."                                              , 
                       "Blank"                                                                  ,
                       "Feel free to use them to your advantage!"                               ,
                       "Blank"                                                                  ,
                       "Good eats are the eats you eat while in HYPER MODE."                    , 
                       "These eats on HYPER MODE give 5 times more points than usual!"          ,
                       "HYPER MODE will activate harmonically , you'll know when that happens." , 
                       "Blank"                                                                  ,
                       "Blank"                                                                  ,
                       "Blank"                                                                  , 
               }                                                                                ,
               *My_Name[] =
               {
                        "    ||   ||  ||===||  ||   ||" 							,
                        "    ||   ||  ||   ||  ||   ||" 							,
                        "    ||   ||  ||===||  ||   ||" 							,
                        "     =====   ||   ||   =====" 								,
               }                   																,                
               *CONTROLS[] =
               {
                        "Move Up    : " ,
                        "Move Left  : " ,
                        "Move Down  : " ,
                        "Move Right : " ,
                        "Activate!  : " ,
               }                        ,
               *Topper  = "|RANK|       | NAME |         |SCORE|"                     , 
               *Quote   = "\"Either make something unique, or make nothing at all.\"" ,
               *File    = "Highscores.BAT"   ;

const int     Star_Sleep = 1500 , 
              Stars_Floor  = 25 , 
              Stars_Roof   = 0  , 
              Stars_L_wall = 0  , 
              Stars_R_wall = 80 ,
              Max_Stars    = 35 ,
              Max_Players      = 10   ,
              Restart_time     = 3    ,
              Hyper_Counts     = 5    , 
			  pause            = 200 ,
			  XWALL            = 20   ,
			  YWALL            = 20   ,

			  XSPACEING        = 23   ,
			  YSPACEING        = 5    ,
				
			  OPTION_PLAY      = 0 ,
			  OPTION_HIGHSCORE = 1 ,
			  OPTION_HELP      = 2 ,
			  OPTION_CONTROLS  = 3 ,
			  OPTION_CREDITS   = 4 , 
			  OPTION_QUIT      = 5 ,
			  OPTION_QUIT_YES  = 0 ,
			  OPTION_QUIT_NOPE = 1 ;
		
			  
char  Head , Tail , Wall , dir , Space , Display[500] ; 

int   b  = 1   ,
	  s  = 123 , 
	  gs = 6*s ,
	  es = 3*s , 
	  ms = 1 ,
	  mms = 1 , 
      framelag  =  30 , 
      Zig_Value =   1 , 
      Zag_Value =   3 , 
      
	  xwall  = XWALL , 
	  ywall  = YWALL ,
	  Xspaceing_Menu    = 40 , 
	  Yspaceing_Menu    = 9 ,
	  Xspaceing_Game    = XSPACEING ,
	  Yspaceing_Game    = YSPACEING ,
	  Xspaceing_Over    = Xspaceing_Menu - 10 ,
	  Yspaceing_Over    = Yspaceing_Menu  ,  
      Xspaceing_Credits = 40 ,
      Yspaceing_Credits = 5 ,

      MAIN_CURRENT    =  0 ,
	  BYE_CURRENT     =  0 ,
	  framecount      =  0 , 
	  LEGEND          = -1 , 
	  New_Scorer      = -1 , 
	  Total_Players   =  0 ,
      Switching       =  0 ,
      Switch_Value    = 10 ,
      Zag_Value_Mod   =  1 ,  
      End             =  0 , 
      
      x , y ,  ax , ay , Score , Eats,Good_Eats, Good_Eats_Per  , Hyper_Count , body     , orangex[10] ,
      xbody[150]  , ybody[150] , Active_Temp   , Hyper_Mode     , Switch_Hub  , Gameover , orangey[10] , 
      Tripping    , Immortal   , epilepsy      , Hide_Body      , Zig_Zag     , Zag_Zig  ,  Pause ,  Monaey ,      
      Lowest_High , Lowest_Low , Lowest_Player , Previous_Score ;							

void  Main_Menu() , 
      Game()      , 
	  Over()      ,
	  Draw()      ,
	  Bye()       ; 

struct Point
{
	int x , y ;
	char Char ;
	Point()
	{
		x = y = 0 ;
	}
	void Set( int X , int Y )
	{
		x = X ;
		y = Y ;
	}

} Stars[Max_Stars] ;

void Go( Point P , char C )
{
	if( P.x > 0 && P.y > 0 && P.x < 80 && P.y < 26 )
	{
		gotoxy( P.x  , P.y ) ;
		cout << C ;
	}

	if( P.x > 0 && P.y > 0 && P.x < 80 && P.y < 26 )
	{
		gotoxy( P.x  , P.y ) ;
		cout << C ;
	}
}

void Move_Stars( int Glitch = 0 )
{
    int Loop_1 ;
    for( Loop_1 = 0 ; Loop_1 < Max_Stars ; Loop_1++ )
    {
         Go(Stars[Loop_1] , ' ') ;
    }
    for( Loop_1 = 0 ; Loop_1 < Max_Stars ; Loop_1++ )     
    {
         Stars[Loop_1].x -= random(2) ;
         Stars[Loop_1].y -= random(2) + 1 ;
         if( Glitch ) Stars[Loop_1].Char = random(127 - 33) + 33 ;
	     if( Stars[Loop_1].y < Stars_Roof   ) Stars[Loop_1].y = Stars_Floor  ;
	     if( Stars[Loop_1].y > Stars_Floor  ) Stars[Loop_1].y = Stars_Roof   ;
	     if( Stars[Loop_1].x < Stars_L_wall ) Stars[Loop_1].x = Stars_R_wall ;
	     if( Stars[Loop_1].x > Stars_R_wall ) Stars[Loop_1].x = Stars_L_wall ;
	     Go(Stars[Loop_1] , Stars[Loop_1].Char ) ;
    }
    framepause(Star_Sleep) ;
}

void Read_Players()
{
    ifstream F(File , ios :: in | ios :: binary ) ;
    Player P  ;
    int Current_Player = 0 ;
    
    F.read((char*)&P , sizeof(P)) ;
    while(!F.eof() && Current_Player < Max_Players) 
    {
        PLAYERS[Current_Player ++] = P ;
        F.read((char*)&P , sizeof(P)) ;
    }
    F.close() ;
    Total_Players = Current_Player ;
    if(PLAYERS[0].Info() != 0 && Total_Players > 0 ) New_Scorer = PLAYERS[0].Info() ;
    if(PLAYERS[1].Info() != 0 && Total_Players > 1 ) LEGEND = PLAYERS[1].Info() ;
    if( LEGEND > Max_Players ) LEGEND = -1 ;
}

void Show_Highscore(int Slow_Motion)
{    
    CLS() ;  
    spaceing( Yspaceing_Menu - 4 , '\n' ) ; 
    spaceing( Xspaceing_Menu - strlen(Topper)/2 ) ; cout << Topper << '\n' ;
    spaceing( Xspaceing_Menu - strlen(Topper)/2 ) ;
    spaceing( strlen(Topper) , '_'  ) ; cout << "\n\n" ; 
    for(int Current_Player = 0  ; Current_Player < Total_Players ; Current_Player ++ ) 
    {
    // && Current_Player <= Max_Players) to only display 10
        if( Slow_Motion ) framepause(3000) ; 
        spaceing(Xspaceing_Menu - 18) ; PLAYERS[Current_Player].Put()  ;
        if( Current_Player == LEGEND      ) cout << " < LEGEND "   ; 
        if( Current_Player >= Max_Players ) cout << " << Out ! "   ;
        if( Current_Player == New_Scorer  ) cout << " < New !  "   ; 
        if( Current_Player != LEGEND
        &&  Current_Player != New_Scorer  ) spaceing(20) ;  
        cout << "\n" ;
    }
    spaceing( Xspaceing_Menu - strlen(Topper)/2) ; spaceing( strlen(Topper) , '_' ) ; cout << "\n" ;    
}

void Player_Sort( Player A[] , int n )
{
    int Flag = 1 ;
    for( int a = 0 ; a < n - 1 ; a ++ )
    {
        Flag = 0 ;
        for( int b = 0 ; b < n - 1 - a ; b ++ )
            if( A[b].Score() < A[b + 1].Score() )
            {
                if( b + 1  == New_Scorer ) New_Scorer -- ; 
                if( b + 1  == LEGEND ) LEGEND -- ; 
                else if( b == LEGEND ) LEGEND ++ ; 
                
                Swap(A[b] , A[b+1]) ;
                Flag = 1 ;
                for( int c = 0 ; c <= Total_Players ; c++ )
                    PLAYERS[c].Set_Rank(c + 1) ;
                Show_Highscore(0) ;
                framepause(8000) ;
            }
    }
}

void New_Highscore(int e , int gep)
{
    Total_Players += 1 ; 
    New_Scorer = Total_Players ;
    PLAYERS[New_Scorer].Get(e , gep) ;
    if(strcmpi(PLAYERS[New_Scorer].Name() , "Chinmay") == 0) LEGEND = New_Scorer ; 
    cls() ; 
}

void Write_Players()
{
    int Loop_1 ; 
    PLAYERS[0].Set_Info( New_Scorer ) ;
    PLAYERS[1].Set_Info( LEGEND ) ;
    ofstream F(File , ios :: binary | ios :: out ) ;
    for( Loop_1 = 0 ; Loop_1 < Total_Players ; Loop_1++ )
        F.write((char*)&PLAYERS[Loop_1] , sizeof(PLAYERS[Loop_1])) ;
    F.close() ;
}

void Put_Apple(int NOT_X = -1 , int NOT_Y = -1)
{
	 int Loop_1 ; 
     ax = 3 + random(xwall - 3) ;
	 ay = 3 + random(ywall - 3) ;
	 if(ax == NOT_X && ay == NOT_Y ) Put_Apple(NOT_X,NOT_Y) ;
	 for(Loop_1 = 0 ; Loop_1 < body ; Loop_1 ++ )
	 {
		  if(xbody[Loop_1] == ax && ybody[Loop_1] == ay) Put_Apple(NOT_X,NOT_Y) ;
	 }
}

void Put_Point( int &THIS_X , int &THIS_Y )
{
     THIS_X = 3 + random(xwall - 3) ;
     THIS_Y = 3 + random(ywall - 3) ;
}

void Walls_Modify( short A )
{
	xwall += A ; Xspaceing_Game -= A/2 ;
	ywall += A ; Yspaceing_Game -= A/2 ;
}

void Walls_Switch()
{
    if(framecount == framelag)
	 {
		  if(Wall == Normal_Wall)
		  {
				Wall = Special_Wall ;
				Tail = Special_Tail ;
				//framecount = special_lag declare to increase hyper time
				if(Hyper_Count <= 1) 
                {
                     Hyper_Count = Hyper_Counts ; 
                     Switching = 1 ;
                 }
                else Hyper_Count -- ; 
		  }
		  else 
		  {
				Wall = Normal_Wall  ;
				Tail = Normal_Tail  ;
				if(Hyper_Count <= 1)
				{
                     Hyper_Count = Hyper_Counts ; 
                     Switching = 1 ;
                }
                else Hyper_Count --  ; 
		  }
	 }
	 if( framecount > framelag ) framecount = 0 ; 
}
void Epilepsy()
{
	if(Tripping&&epilepsy) if (xwall < XWALL + 8) Walls_Modify(2) ; else  Tripping = 0 ;
	else if(xwall > XWALL) Walls_Modify(-2) ; else Tripping = 1 ;
}

void Ability_Nothing(){}  

void Ability_Teleport()
{
	 if( !(xbody[body] > 0 && xbody[body] < xwall) ) return ;
	 if( !(ybody[body] > 0 && ybody[body] < ywall) ) return ;
	 x = xbody[body] ;
	 y = ybody[body] ;
	 if     (ybody[body-1] > ybody[body]) dir = 'u' ;  
	 else if(ybody[body-1] < ybody[body]) dir = 'd' ;
	 else if(xbody[body-1] > xbody[body]) dir = 'l' ;
	 else if(xbody[body-1] < xbody[body]) dir = 'r' ;
}

void Ability_Reverse()
{
    int Loop_1 , Loop_2 ; 
	x = xbody[body] ;
	y = ybody[body] ;
	if     (ybody[body-1] > ybody[body]) dir = 'u' ;  
	else if(ybody[body-1] < ybody[body]) dir = 'd' ;
	else if(xbody[body-1] > xbody[body]) dir = 'l' ;
	else if(xbody[body-1] < xbody[body]) dir = 'r' ;
	for(Loop_1 = 0 , Loop_2 = body ; Loop_1 <= body/2 ; Loop_1++ , Loop_2 --)
	{
		swap(xbody[Loop_1] , xbody[Loop_2]) ;
		swap(ybody[Loop_1] , ybody[Loop_2]) ;
	}
}
void Ability_Pause()    { Pause == 1 ? Pause = 0 : Pause = 1 ; }
void Ability_Immortal() { Immortal  = 1 ; }
void Ability_Epilepsy() { epilepsy  = 1 ; Tripping = 1 ;  }   
void Ability_Invisible(){ Hide_Body = 1 ; } 
void Ability_Zigzag()   { Zig_Zag = 1 ; }
void Ability_Zagzig()   { Zag_Zig = 1 ; } 
void Ability_Blind()    { Space = Special_Space ;}
void Ability_Money()    { Monaey = 1 ; } 
void Ability_Feast()   
{
     int Loop_1 ; 
     for( Loop_1 = 0 ; Loop_1 < 10 ; Loop_1++ )
     {
          Put_Point( orangex[Loop_1] , orangey[Loop_1] ) ;
     }      
}
void Fresh_Ability()
{
     int Loop_1 ; 
     if(Zig_Zag || Zag_Zig) cls() ; 
     for( Loop_1 = 0 ; Loop_1 < 10 ; Loop_1++ )
     {
          orangex[Loop_1] = orangey[Loop_1] = -1 ; 
     }
     Zig_Zag = 0 ; 
     Zag_Zig = 0 ; 
     Immortal = 0 ;
     Hide_Body = 0 ;
     Monaey = 0 ;
     Hyper_Mode = 1 ; 
     Space = Normal_Space ; 
     if( ax > xwall || ay > ywall ) Put_Apple() ; 
      
}
void Null_Ability(Ability &Abi )
{
     strcpy(Abi.Name,"            ") ; 
     strcpy(Abi.Type,"       ") ; 
     Abi.Execute = Ability_Nothing ; 
} 
void Make_Ability(Ability &Abi) 
{
     int _ = random(60) ;
     if(_ >=  0 && _ < 10){ strcpy(Abi.Name , "Pause       ") ; Abi.Execute = Ability_Pause    ; }
     if(_ >= 10 && _ < 20){ strcpy(Abi.Name , "Reverse     ") ; Abi.Execute = Ability_Reverse  ; }
     if(_ >= 20 && _ < 30){ strcpy(Abi.Name , "Teleport    ") ; Abi.Execute = Ability_Teleport ; }
     if(_ >= 30 && _ < 35){ strcpy(Abi.Name , "ZIG ZAGGY ! ") ; Abi.Execute = Ability_Zigzag   ; } 
     if(_ >= 35 && _ < 40){ strcpy(Abi.Name , "ZAGGY ZIG ! ") ; Abi.Execute = Ability_Zagzig   ; } 
     if(_ >= 40 && _ < 45){ strcpy(Abi.Name , "Immortality ") ; Abi.Execute = Ability_Immortal ; }
     if(_ >= 45 && _ < 50){ strcpy(Abi.Name , "Blindedness ") ; Abi.Execute = Ability_Blind    ; }
     if(_ == 50) { strcpy(Abi.Name , "Eat Feast!! ") ; Abi.Execute = Ability_Feast     ; }
     if(_ == 51) { strcpy(Abi.Name , "Invisible!  ") ; Abi.Execute = Ability_Invisible ; }
     if(_ == 52) { strcpy(Abi.Name , "||Epilepsy||") ; Abi.Execute = Ability_Epilepsy  ; }
     if(_ >= 53) { strcpy(Abi.Name , "$$ MONEY $$ ") ; Abi.Execute = Ability_Money     ; }
     
     if(  strcmp(Abi.Name , "Teleport    ") == 0 
     ||   strcmp(Abi.Name , "Reverse     ") == 0 
     //||   strcmp(Abi.Name , "$$ MONEY $$ ") == 0 
     ||   strcmp(Abi.Name , "Pause       ") == 0 ) 
          strcpy(Abi.Type , "Active " ) ;
     else strcpy(Abi.Type , "Passive" ) ;  
     
 }
     
 void Switch_Ability()
 {
      switch(Switching)
      {
          case 1 : Null_Ability(A[0]) ; Fresh_Ability() ; // break ;
          case 2 : 
          case 3 :
          case 4 : Swap(A[Switching - 1] , A[Switching]) ; Switching += 1 ; break ;
      }
      if(Switching == 5) { Swap( A[Switch_Value] , A[Switch_Value - 1] ) ; Switch_Value -= 1 ; } 
      if(Switching == 5 && Switch_Value == 3) 
      { 
           Switch_Value = 10 ; Switching = 0 ; 
           Make_Ability(A[10]) ;
      }    
      if( strcmp(A[0].Type , "Passive" ) == 0 ) { A[0].Execute() ; A[0].Execute = Ability_Nothing ; }
      else Active_Temp = 4 ; 
}
           
int main()
{
    
    float x = 40 , y = 13 , Percent = 0 ; 
    char c ; 
    while( 1 ) {
        theter = pi*(Percent/50) ; 
        gotoxy( x - Percent/100 , y ) ; 
        cout << Percent << "%" ; 
        if( Percent < 100 ) { 
            circle( x , y , 10 , '#' , 2 ,  true ) ;
            gotoxy( x - 3, y - 2 ) ; 
            cout << "Loading" ;
        }
        else {  
            gotoxy( x - 4 , y + 2 ) ; 
            cout << "Finished!" ; 
            break ; 
        }
        if( Percent == 99 ) {  gotoxy( x - 3 , y - 2 ) ; cout << "       " ; }
        if( Percent < 100 ) Percent++ ; 
    }    
    theter = 2.5*pi ; 
    circle( x , y , 11 , '#' , 2 , true ) ; 
    theter = 0 ; 
    while( theter <= 2.5*pi ) { 
        circle( x , y , 11 , '$' , 1 ) ; 
        theter += 0.3 ; 
    } 
    gotoxy( x - 13 , y - 2 ) ; 
    cout << "Press any key to continue." ; 
    getch() ; 
     cls() ; 
    
     int Loop_1 ;
     Read_Players() ;
	 for( Loop_1 = 0 ; Loop_1 < Max_Stars ; Loop_1++ )
	 {
		  Stars[Loop_1].Set( random(Stars_R_wall - Stars_L_wall) + Stars_L_wall ,
			                 random(Stars_Floor  -  Stars_Roof ) + Stars_Roof   ) ;
	      Stars[Loop_1].Char = '*' ;
	 }
     while(! End) Main_Menu() ; 
     return 1 ; 
}

void Back(int Forgetten = 0 , int Arg1 = 0 , int Arg2 = 0 )
{
     char Loop_1 ; 
     spaceing(10 , '\b') ; 
	 cout << POINTER << "Return to Main Menu." ;
     while(Loop_1 != Power)
     {
          if( Forgetten ) 
               while( !kbhit() ) 
               {
                    Move_Stars() ;
                    gotoxy(Arg1 - 10 , Arg2 ) ;
                    cout << POINTER << "Return to Main Menu." ;
                    framepause(1500) ; 
                }
          Loop_1 = getch() ;
      }
     cls() ; 
}

void Help()
{
     int Loop_1 , Loop_2 ;
     CLS() ; 
     spaceing(5 , '\n') ;
       
     Loop_1 = -1 ;
     while(Loop_1++ < 13)
     { 
            if(strcmp(Halp[Loop_1],"Blank") == 0){ spaceing(50) ;}
            else {
                 spaceing(Xspaceing_Menu - strlen(Halp[Loop_1])/2) ; 
                 for(Loop_2 = 0 ; Loop_2 < strlen(Halp[Loop_1]) ; Loop_2++){
                      cout << Halp[Loop_1][Loop_2] ; framepause(1000) ; }  
                 }
            cout << '\n' ; 
     } 
     spaceing(Xspaceing_Menu) ;
     Back() ;
     cls() ; 
}

void Controls()
{
     CLS() ; 
     int Loop_1 ; 
     char Loop_2 ; 
     while(!kbhit() )
     {
          Move_Stars() ; CLS() ;
          spaceing(Yspaceing_Menu - 1 ,'\n' ) ;
          spaceing(Xspaceing_Menu - 10 ) ;
          cout << "<---|: CONTROLS :|--->\n" ;
          spaceing(70) ; 
          cout << "\n" ; 
          for( Loop_1 = 0 ; Loop_1 < 5 ; Loop_1++ )
          {
               spaceing(Xspaceing_Menu - 10) ; 
               cout << CONTROLS[Loop_1] ; 
               spaceing(5) ; 
               if(CONTROL_KEYS[Loop_1] == ' ') cout << "\b\bSpace" ; 
               else cout << CONTROL_KEYS[Loop_1] ; 
               spaceing(5) ; 
               cout << "\n" ;      
          }
          spaceing(3 , '\n') ; 
          spaceing(Xspaceing_Menu - 10) ; 
          cout << POINTER << "Return to Main Menu." ;
     }
     Loop_2 = getch() ;
     if( Loop_2 != Power ) Controls() ; 
     else cls() ;  
 }
void Credits()
{
     cls() ; 
     spaceing(Yspaceing_Credits , '\n') ;
     spaceing(Xspaceing_Credits - 7) ;
     cout << "<: GAME BY :> \n\n" ;
     int Loop_1 , Loop_2 ;
     for( Loop_1 = 0 ; Loop_1 < 8 ; Loop_1++ )
     {
         spaceing(Xspaceing_Credits - strlen(My_Name[Loop_1])/2) ; 
         for( int Loop_2 = 0 ; Loop_2 < strlen(My_Name[Loop_1]) ; Loop_2++ )
         {
             cout << My_Name[Loop_1][Loop_2] ;
             framepause(1500) ; 
         }
         cout << "\n" ;
     }
     spaceing(Xspaceing_Credits) ;
     Back(1 , Xspaceing_Credits , Yspaceing_Credits + 16 ) ;
}

void Run_Game() 
{ 
     int Loop_1 ;
     cls() ; Game() ; 
	 Fresh_Ability() ; 
	 int x = body ;  
	 for( Loop_1 = 0 ; Loop_1 <= x ; Loop_1++)
	 {
			body-- ;
			Draw() ;
			framepause(pause) ;
	 }
	 Over() ;
}

void Main_Menu_Select(int SELECT)
{
	 switch(SELECT)
	 {
		  case OPTION_PLAY      : Run_Game() ; break ;
		  case OPTION_HIGHSCORE : Show_Highscore(1) ; cout << '\n' ; 
                                  spaceing(Xspaceing_Menu) ; Back() ; break ;
		  case OPTION_HELP      : Help()     ; break ;
		  case OPTION_CONTROLS  : Controls() ; break ;
		  case OPTION_CREDITS   : Credits()  ; break ; 
		  case OPTION_QUIT      : cls() ; Bye() ; break ;
	 }
}

void Main_Menu()
{	 
	 int  Loop_1 ; 
     char Loop_2 ;
     CLS() ;
     for( Loop_1 = 0 ; Loop_1 < Max_Stars ; Loop_1++ )
	 {
	      Stars[Loop_1].Char = '*' ;
	 }
     while( !kbhit() )
     {
          Move_Stars() ; 
          gotoxy(0 , Yspaceing_Menu) ; 
	      for( Loop_1 = OPTION_PLAY ; Loop_1 <= OPTION_QUIT ; Loop_1 ++ )
	      {
               spaceing(Xspaceing_Menu) ; 
		       if( MAIN_CURRENT == Loop_1 ) cout << POINTER << MAIN_MENU_1[Loop_1] << endl ;
		       else cout << MAIN_MENU_2[Loop_1] << endl ;
          }
     }
	 Loop_2 = getch() ;
	 switch(Loop_2)
	 {
		  case Up    : if( MAIN_CURRENT > OPTION_PLAY ) MAIN_CURRENT-- ; Main_Menu() ; break ;
		  case Down  : if( MAIN_CURRENT < OPTION_QUIT ) MAIN_CURRENT++ ; Main_Menu() ; break ;
		  case Power : Main_Menu_Select(MAIN_CURRENT) ; break ; 
	 }
}

void Bye_Select(int SELECT) 
{
     switch(SELECT)
     {
          case OPTION_QUIT_YES  : cls() ; Main_Menu() ; break ; 
          case OPTION_QUIT_NOPE : End = 1 ; 
                                  cls() ; 
                                  spaceing(10,'\n') ;
                                  spaceing(30) ;
                                  cout << "bye." ;
                                  break ;
     }
}
     
void Bye()
{
     int  Loop_1 ;
     char Loop_2 ;
     CLS() ;
	 while( !kbhit() ) 
     {
          Move_Stars(1) ; 
          gotoxy(Xspaceing_Menu - 10 , Yspaceing_Menu ) ; 
	      cout << "< Can't you play a little longer ?\n\n\n" ; 
	      for( Loop_1 = 0 ; Loop_1 <= OPTION_QUIT_NOPE ; Loop_1 ++ )
	      {
               spaceing(Xspaceing_Menu) ; 
		       if( BYE_CURRENT == Loop_1 ) cout << POINTER << BYE_SCREEN_1[Loop_1] << "\n" ;
		       else cout << BYE_SCREEN_2[Loop_1] << "\n" ;
          }
     }
	 Loop_2 = getch() ;
	 switch(Loop_2)
	 {
		  case Up    : if( BYE_CURRENT > OPTION_QUIT_YES  ) BYE_CURRENT-- ; Bye() ; break ;
		  case Down  : if( BYE_CURRENT < OPTION_QUIT_NOPE ) BYE_CURRENT++ ; Bye() ; break ;
		  case Power : Bye_Select(BYE_CURRENT) ; break ; 
	 }
}
	
char Current_Location_Point( int LOCATION_X , int LOCATION_Y)
{    
	 int Loop_1 ;
     if(LOCATION_Y == 0  || LOCATION_Y == ywall) return Wall  ; 
	 if(LOCATION_X == 0  || LOCATION_X == xwall) return Wall  ; 
	 if(LOCATION_X == x  && LOCATION_Y == y    ) return Head  ; 
	 if(LOCATION_X == ax && LOCATION_Y  == ay  ) return Apple ; 
	 for( Loop_1 = 0 ; Loop_1 < 10 ; Loop_1++ ) 
	 if(LOCATION_X == orangex[Loop_1] && LOCATION_Y == orangey[Loop_1]) return Orange ; 
     for( Loop_1 = 0 ; Loop_1 <= body ; Loop_1++)
	 {
		  if(LOCATION_X == xbody[Loop_1] && LOCATION_Y  == ybody[Loop_1])
		  {
				if( ! Hide_Body ) return Tail ; 
		  }
	 }
	 return Space ; 
}

void Current_Location_Line_Pre( int LOCATION_Y ) 
{
    int Loop_1 , Loop_2 ; 
    static int Loop_3 ;
    
    char Line[20] ;
    Loop_1 = 0 ; 
    switch(LOCATION_Y)
    {
        case 0 : Loop_1 = 1 ; strcpy(Line , "- Score -") ;  break ;
        case 1 : Loop_1 = 2 ; break ;
        case 3 : Loop_1 = 1 ; strcpy(Line , "- Good Eats -") ; break ; 
        case 4 : Loop_1 = 3 ; break ;
        case 6 : if(Score > PLAYERS[0].Score()){Loop_1 = 1 ; strcpy(Line , "TOP PLAYER BEATEN!") ;}break ; 
        case 7 : if(Score < PLAYERS[0].Score()){Loop_1 = 1 ; strcpy(Line , "AIM FOR") ; }break ;
        case 8 : Loop_1 = 4 ; break ;
        case 9 : if(Score < PLAYERS[0].Score()){Loop_1 = 1 ; strcpy(Line , "TO BEAT PLAYER") ;}break ;
        case 10: if(Score < PLAYERS[0].Score()){Loop_1 = 1 ; strcpy(Line , PLAYERS[Lowest_Player].Name()) ;}break ;
    }
    // 1 is lines 2 is score 3 is goodeatsper 4 highgihg
    switch(Loop_1)
    {
        case 1 : spaceing(10 + strlen(Line)/2 , '\b') ; cout << Line ; 
                 spaceing(10 + strlen(Line)/2 - strlen(Line) ) ; break ;
        case 2 : Loop_2 = 1 ; if ( Score > Lowest_Low ) Loop_2++ ; if( Score > Lowest_High ) Loop_2 ++ ; 
                 spaceing(10 + 2 + Loop_2 + intlen(Score)/2 , '\b') ; 
                 spaceing(Loop_2 , ':') ;
                 cout << "> " << Score << " <" ;
                 spaceing(Loop_2 , ':') ; 
                 spaceing(10 - 2 - Loop_2 + intlen(Score)/2 - intlen(Score) ) ; break ;
        case 3 : //if(Previous_Score <= Score && ___ == 3 ) ___ = 0 ; // FLASH FLASH FAST BOI 
                 if (Good_Eats_Per < 70 && Loop_3 > 1) Loop_3 -- ; 
                 if (Good_Eats_Per == 100 && Loop_3 < 3) Loop_3++ ; 
                 if (Good_Eats_Per != 100 && Loop_3 < 2 && Good_Eats_Per > 70) Loop_3++ ; 
                 spaceing(10 + 3 + Loop_3 + intlen(Good_Eats_Per)/2 , '\b') ;
                 spaceing(Loop_3 , '|') ; 
                 cout << ">  " << Good_Eats_Per << "% <" ;
                 spaceing(Loop_3 , '|') ;
                 spaceing(10 - 3 - Loop_3 + intlen(Good_Eats_Per)/2 - intlen(Good_Eats_Per) ) ; break ;
        case 4 : if(Score < PLAYERS[0].Score())
                 {
                     spaceing(10 + 3 + intlen(Lowest_High)/2 , '\b') ; cout << "<  " << Lowest_High << "+ >" ;
                     spaceing(10 - 3 + intlen(Lowest_High)/2 - intlen(Lowest_High) ) ; break ;
                 }
                 break ;
     }
}

void Current_Location_Line_Post( int LOCATION_Y )
{
     switch(LOCATION_Y)
     {
         case 0  : cout << "\bX==:> " ;
                   if(Switching) cout << "Switching Ability!" ; 
                   else cout << "Next Ability in " << Hyper_Count << "." ; break ; 
         case 2  : cout << " :> Current Ability " ; 
                   spaceing(4 - framecount%2) ;
                   cout << POINTER ; 
                   spaceing(framecount%2) ; 
                   cout << A[0].Name ; break ;
         case 3  : cout << " :> Ability Type " ;
                   if(strcmp(A[0].Type,"Active ")==0)
                   {spaceing(4  - Active_Temp,'-');spaceing(Active_Temp);if(Active_Temp > 0)Active_Temp--;}
                   else spaceing(3) ;
                   cout << ":> " << A[0].Type ; break ;
         case 6  : cout << " Coming Up Next "   ; 
                   if(Hyper_Count == 1){ spaceing(framecount%4 ,'!') ; spaceing(4 - framecount%4)  ; }
                   else cout << "!     " ;
                   break ; 
         case 7  : cout << "||>  " ; break  ;
         case 8  : cout << "|>  "  ; break  ;
         case 9  : cout << ">  "   ; break  ;
     }
     if(LOCATION_Y > 6 && LOCATION_Y < 16) cout << A[LOCATION_Y - 6].Name ;
}
 
void Header()
{
	 spaceing(Xspaceing_Game )       ;
	 if(Gameover)  cout << "<GAME OVER>" ;
	 spaceing(xwall , ' ') ;
	 if(Wall == Special_Wall) { Gameover ? spaceing(17 , '\b') : 
     spaceing(6 + framecount%(xwall - 6) , '\b') ; cout << "<HYPER> " ; }
	 else spaceing(20) ; 
	 cout << '\n' ;
}

void Tailer()
{
     if(Score > Lowest_Low)
     {
         cout << "\n" ;
         spaceing(Xspaceing_Game + xwall/2 - 7 - strlen(PLAYERS[Lowest_Player+1].Name())/2) ;
         cout << "You've beaten " << PLAYERS[Lowest_Player+1].Name() << " !              \n" ;
         spaceing(Xspaceing_Game + xwall/2 - 8) ; 
         if(Lowest_Player == 0) cout << "\bTop Position" ;
         else cout << "Position " << Lowest_Player + 2 ;
         cout << " Secured.  \n" ;
     }
 }
void Setup()
{    
     int Loop_1 ;
     Tripping = 0 ; 
     Lowest_Player = 9 ;
     Lowest_High = Lowest_Low = PLAYERS[Lowest_Player].Score() ; 
     Loop_1 = -1 ; while(Loop_1++ <= 10) Null_Ability(A[Loop_1]) ; 
     Hyper_Count = Hyper_Counts ; 
     Hyper_Mode = 1 ;
     for( Loop_1 = 0 ; Loop_1 < 10 ; Loop_1++)
     {
          orangex[Loop_1] = orangey[Loop_1] = -1 ;
     }
	 Put_Point(x,y) ; 
	 Head  = Start_Head ; 
     Tail  = Start_Tail ;
     Wall  = Start_Wall ; 
     Space = Start_Space ; 
	 dir = ' ' ;
	 for(Loop_1 = 0 ; Loop_1 < body ; Loop_1 ++){xbody[Loop_1] = -1 ;ybody[Loop_1] = -1 ;}
	 body  = 1   ;
	 Eats  = Good_Eats = Good_Eats_Per = Score = 0 ;
	 Put_Apple(x,y) ;
	 Switch_Hub = Gameover = 0  ;
     Fresh_Ability() ; 	 
}
    
void Draw()
{
	 unsigned short Loop_1 , Loop_2 ; 
     CLS() ; 
	 spaceing(Yspaceing_Game , '\n') ; 
	 Header() ; 
	 for( Loop_1 = 0 ; Loop_1 <= ywall ; Loop_1 ++)
	 {
		  spaceing(Xspaceing_Game) ; 
		  if( ! Gameover ) Current_Location_Line_Pre(Loop_1) ; 
		  if( (Loop_1%2 == 0) && Zig_Zag ) spaceing(Zig_Value) ;
		  if( (Loop_1%2 == 0) && Zag_Zig ) spaceing(Zag_Value) ; 
		  if( (Loop_1%2 != 0) && Zag_Zig ) spaceing(3 - Zag_Value) ; 
		  for(Loop_2 = 0 ; Loop_2 <= xwall ; Loop_2++)
		  {
		        if( (Loop_2%2 == 0) && Zig_Zag ) cout << Current_Location_Point( Loop_2 , Loop_1 + Zig_Value  ) ;
				else cout << Current_Location_Point( Loop_2 , Loop_1 ) ; 
		  }
		  if( ! Gameover ) Current_Location_Line_Post(Loop_1) ; 
		  cout << '\n' ; 
	 }
	 if( ! Gameover ) Tailer() ; 
	 framecount += 1 ;
	 framepause(pause) ;
}

void Move()
{
	 switch(dir)
	 {
		  case 'u' : Head = '^' ; y-- ; break; 
		  case 'd' : Head = 'v' ; y++ ; break; 
		  case 'l' : Head = '<' ; x-- ; break; 
		  case 'r' : Head = '>' ; x++ ; break; 
	 }
}

void Input()
{
	 if(kbhit())
	 {
		  switch(getch())
		  {
				case Up    : if(dir != 'd') dir = 'u' ; break ;
				case Down  : if(dir != 'u') dir = 'd' ; break ;
				case Left  : if(dir != 'r') dir = 'l' ; break ;
				case Right : if(dir != 'l') dir = 'r' ; break ;
				case Power : A[0].Execute() ; break ;
				case q     : Gameover = 1 ;
		  }
	 }
}

void Logic()
{
	 int Loop_1 ;
	 int prevX = xbody[0] , prev2X;
	 int prevY = ybody[0] , prev2Y;
	 xbody[0]  = x ; ybody[0] = y ;
	 for(Loop_1 = 1 ; Loop_1 <= body ; Loop_1++)
	 {
		  prev2X = xbody[Loop_1]; xbody[Loop_1] = prevX ;
		  prev2Y = ybody[Loop_1]; ybody[Loop_1] = prevY ;  
		  prevX  = prev2X  ;
		  prevY  = prev2Y  ; 
	 }
	 if(!Immortal)
		  for( Loop_1 = 2 ; Loop_1 < body ; Loop_1++)
				if(x == xbody[Loop_1] && y == ybody[Loop_1]){ cls() ; Wall = ' ' ;  Gameover = 1; }
	 if (x == ax && y == ay)
	 {  
		  body  += b ;
		  Previous_Score = Score ; 
		  Score += Good_Eats_Per*( 0.01*s + 1 ) ; 
		  if(Wall == Normal_Wall) Score += s ;
		  else {  Good_Eats++ ; Score += gs  ;  }
		  Eats  ++ ; 
		  Good_Eats_Per = 100*Good_Eats/Eats ;
          Put_Apple(x,y);
	 }
	 for( Loop_1 = 0 ; Loop_1 < 10 ; Loop_1++ )
	 {
          if ( x == orangex[Loop_1] && y == orangey[Loop_1] )
          {
              Previous_Score = Score ;
              Score += es ;
              Put_Point(orangex[Loop_1],orangey[Loop_1]) ;
          }
      }
	      
	 if ((x > xwall - 1 ) && (dir == 'r')) x = 1         ;
	 if ((x < 1)          && (dir == 'l')) x = xwall - 1 ;    
	 if ((y > ywall - 1 ) && (dir == 'd')) y = 1         ;
	 if ((y < 1)          && (dir == 'u')) y = ywall - 1 ; 
	 Epilepsy() ;
	 if(Tripping&&!( xwall > XWALL )&&epilepsy&&(strcmp(A[0].Name , "||Epilepsy||") != 0)) 
     { cls() ; Tripping = 0 ; epilepsy = 0 ;} 
     if (Hyper_Mode) Walls_Switch() ; 	
     if (Switching) Switch_Ability() ;
     if (Switch_Hub == 0){ Make_Ability(A[10]) ; Switching = 4 ; Switch_Hub++ ; }
     if (Switch_Hub == 1 && ! Switching ) { Make_Ability(A[10]) ; Switching = 3 ; Switch_Hub++ ; } 
     if (Switch_Hub == 2 && ! Switching ) { Make_Ability(A[10]) ; Switching = 2 ; Switch_Hub++ ; } 
     if (Switch_Hub == 3 && ! Switching ) { Make_Ability(A[10]) ; Switching = 1 ; Switch_Hub++ ; }   
     if (Score > Lowest_High && Lowest_Player > 0) 
     {
          Lowest_Player-- ; 
          Lowest_High = PLAYERS[Lowest_Player].Score() ;
     }
     if(Zag_Zig)
     {
          if((Zag_Value == 0 && Zag_Value_Mod == -1)||(Zag_Value == 3 && Zag_Value_Mod == 1)) 
          Zag_Value_Mod *= -1 ; 
          Zag_Value += Zag_Value_Mod ;
     }       
     if(Monaey) 
     {
         if(Good_Eats_Per < 100) Score += ms + (100 - Good_Eats_Per) ; 
         Good_Eats_Per += ms ; 
     } 
}
void Game()
{
	 Setup();
	 while(!Gameover)
	 {
		  Draw();
		  Input();
		  if(!Pause){ Move() ; Logic() ; }
	 }
}

void Over()
{
	 cls() ;
	 spaceing(Yspaceing_Over , '\n' ) ;
	 spaceing(Xspaceing_Over  )        ; 
	 cout << "Game Over\n"    ;
	 spaceing(Xspaceing_Over) ;
	 if(Score > Lowest_Low) 
     {
          cout << "New Highscore!\n\n" ;
          spaceing(Xspaceing_Over) ;
          New_Highscore(Score , Good_Eats_Per) ;
          Player_Sort(PLAYERS , Total_Players + 1) ; 
          Write_Players() ;
          cout << "\n\n" ; 
     }
     else 
     {
          cout << "Better Luck Next Time!\n" ; 
	      spaceing(Xspaceing_Over) ;
	      cout << "Eats        : " << Eats << '\n' ;
	      spaceing(Xspaceing_Over) ;
	      cout << "Good eats   : " << Good_Eats    ; 
	      Good_Eats_Per == 100 ? cout << "(100%)" : cout << "(" << Good_Eats_Per << "%)" ; 
	      cout << '\n' ;
	      spaceing(Xspaceing_Over) ;
	      cout << "Final Score : " << Score << "\n\n" ;
     }
     spaceing(Xspaceing_Over + 10 ) ; 
     Back() ; 
}  
