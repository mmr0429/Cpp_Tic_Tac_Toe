/*
Written by Maciej Rutkowski github/mmr0429
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
//Plansza
int main();
class Board
{
friend int main();
protected:
  int brd[9];
  Board() //Konstruktor
  {
    for(int i=0;i<9;i++)
    {
      brd[i]=0;
    }
  }

public:
  bool test_place(int plc)
  {
    if(brd[plc]!=0){return false;}
    else{return true;}
  }
  void show()
  {
    system("clear");
    std::cout<<std::endl;
    std::cout<<brd[0]<<" "<<brd[1]<<" "<<brd[2]<<std::endl;
    std::cout<<brd[3]<<" "<<brd[4]<<" "<<brd[5]<<std::endl;
    std::cout<<brd[6]<<" "<<brd[7]<<" "<<brd[8]<<std::endl;
    std::cout<<std::endl;
  }
  void show_start()
  {
    system("clear");
    std::cout<<std::endl;
    std::cout<<"1"<<" "<<"2"<<" "<<"3"<<std::endl;
    std::cout<<"4"<<" "<<"5"<<" "<<"6"<<std::endl;
    std::cout<<"7"<<" "<<"8"<<" "<<"9"<<std::endl;
    std::cout<<std::endl;
  }
  void set_place(int ind,int who)
  {
    brd[ind]=who;
  }
  int who_win()
  {
    int p1=1,p2=2;
    if (((brd[0]==p1)&&(brd[3]==p1)&&(brd[6]==p1))||
    ((brd[1]==p1)&&(brd[4]==p1)&&(brd[7]==p1))||
    ((brd[2]==p1)&&(brd[5]==p1)&&(brd[8]==p1))){return p1;}
    else if (((brd[0]==p1)&&(brd[1]==p1)&&(brd[2]==p1))||
    ((brd[3]==p1)&&(brd[4]==p1)&&(brd[5]==p1))||
    ((brd[6]==p1)&&(brd[7]==p1)&&(brd[8]==p1))){return p1;}
    else if (((brd[0]==p1)&&(brd[4]==p1)&&(brd[8]==p1))||
    ((brd[2]==p1)&&(brd[4]==p1)&&(brd[6]==p1))){return p1;}

    else if (((brd[0]==p2)&&(brd[3]==p2)&&(brd[6]==p2))||
    ((brd[1]==p2)&&(brd[4]==p2)&&(brd[7]==p2))||
    ((brd[2]==p2)&&(brd[5]==p2)&&(brd[8]==p2))){return p2;}
    else if (((brd[0]==p2)&&(brd[1]==p2)&&(brd[2]==p2))||
    ((brd[3]==p2)&&(brd[4]==p2)&&(brd[5]==p2))||
    ((brd[6]==p2)&&(brd[7]==p2)&&(brd[8]==p2))){return p2;}
    else if (((brd[0]==p2)&&(brd[4]==p2)&&(brd[8]==p2))||
    ((brd[2]==p2)&&(brd[4]==p2)&&(brd[6]==p2))){return p2;}

    else if((brd[0]!=0)&&(brd[1]!=0)&&(brd[2]!=0)&&(brd[3]!=0)&&(brd[4]!=0)&&(brd[5]!=0)&&(brd[6]!=0)&&(brd[7]!=0)&&(brd[8]!=0)&&(brd[9]!=0))
    {
      return 9;
    }

    else{return 0;}
  }
};

//Klasa z ktorej sie dziedziczy
class Player
{
protected:
  int player_num;
public:
  virtual void move(Board *tst)=0;
};
//AI
//TO DO
class Skynet :public Player
{

};

//GRACZ
class Human :public Player
{
public:
  Human(int nm){this->player_num=nm;}
  void move(Board* tst)
  {
    bool good=true;
    while(good)
    {
      std::cout<<"Where would You like to move ?\n";
      int where;
      if(std::cin>>where)
      {
        where=where-1;
        if((where>=0)&&(where<9))
        {
          if(tst->test_place(where))
          {
            tst->set_place(where,this->player_num);
            good=false;
          }
        }
        std::cout<<"Wrong move ...\n";
      }
      else
      {
        std::cout<<":( :( Fatal Error :( :(\nGo away ...\n(or run program again ...)\n";
        exit(1);
      }

    }
  }
};

int main()
{
  bool game1v2=true;
  Board game_board;
  Human player1(1);
  Human player2(2);
  game_board.show_start();
  std::cout<<"Press Enter to start\n";
  int score;
  getchar();
  while(game1v2) //gra
  {
    game_board.show();
    std::cout<<"Player 1\n";
    player1.move(&game_board);
    game_board.show();

    score = game_board.who_win();
    if(score==1)
    {
      std::cout<<"Player 1 is WINNER !!!\n";
      break;
    }
    else if(score==2)
    {
      std::cout<<"Player 2 is WINNER !!!\n";
      break;
    }
    else if(score==9)
    {
      std::cout<<":(\n";
      break;
    }

    game_board.show();
    std::cout<<"Player 2\n";
    player2.move(&game_board);
    game_board.show();

    score = game_board.who_win();
    if(score==1)
    {
      std::cout<<"Player 1 is WINNER !!!\n";
      break;
    }
    else if(score==2)
    {
      std::cout<<"Player 2 is WINNER !!!\n";
      break;
    }
    else if(score==9)
    {
      std::cout<<":(\n";
      break;
    }

    //game1v2=false; //TRZEBA USUNAC POD KONIEC
  }
  return 0;
}
