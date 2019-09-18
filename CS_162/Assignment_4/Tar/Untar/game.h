/*****************************************************************************************
Program/File name:	game.h
Author:				Arunav Biswas
Date				May 29, 2018
Description:		Runs game
Input:				mostly char
Output:				the game
*****************************************************************************************/
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "./Ants.hpp"
#include "./Bee.hpp"

using std::vector;


class Game{
	private:
		vector < vector <Bug*> > M;
		int food;
	public:
		Game();
		~Game();
		/*********************************************************************
		** Function:		setBoard()
		** Description:		Sets board
		** Parameters:		Vector<vector<Bug*>> Var
		** Pre-Condition:	initialized vector 2d
		** Post Condition:	void
		*********************************************************************/
		void setBoard(vector < vector <Bug*> > M);
		/*********************************************************************
		** Function:		win()
		** Description:		returns if win
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		bool win();
		/*********************************************************************
		** Function:		BeeAttack()
		** Description:		makes bees attack
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void BeeAttack();
		/*********************************************************************
		** Function:		win()
		** Description:		returns if lose
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		bool lose();
		/*********************************************************************
		** Function:		playgame
		** Description:		plays game, Takes in parameter for easy or hard mode.
		** Parameters:		integer 1 or 0
		** Pre-Condition:	NA
		** Post Condition:	NA
		*********************************************************************/
		void playgame(int);
		/*********************************************************************
		** Function:		printBoard
		** Description:		prints board
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void printBoard();
		/*********************************************************************
		** Function:		makebee
		** Description:		makes bee at M[0] (uses push_back())
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void makebee();
		/*********************************************************************
		** Function:		getAnt
		** Description:		gets ant to place, then calls placeAnt
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void getAnt();
		/*********************************************************************
		** Function:		placeAnt
		** Description:		places ant
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void placeAnt(int, int);
		/*********************************************************************
		** Function:		movebee
		** Description:		moves bee by one space
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void movebee();
		/*********************************************************************
		** Function:		win()
		** Description:		returns if win
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		// bool checkBoardEnd(vector<Bug*>::iterator&);
		/*********************************************************************
		** Function:		printoptions()
		** Description:		prints options for picking ants
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void printoptions();
		/*********************************************************************
		** Function:		getinput
		** Description:		gets input inbetween a certain range
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		int getinput(int, int);
		/*********************************************************************
		** Function:		checkifBlock
		** Description:		checks if there is an ant that is blocking the bee
							from moving
		** Parameters:		ints, lower bound, upper bound
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		bool checkifBlock(int, int);
		/*********************************************************************
		** Function:		PrintEmptySpaces
		** Description:		printss empty spaces for x number of time
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void PrintEmptySpaces(int);
		/*********************************************************************
		** Function:		checkFoodCost
		** Description:		checks if user is about to go into a negative balance
							of food
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	returns bool
		*********************************************************************/
		bool checkFoodCost(int);
		/*********************************************************************
		** Function:		EvaluateBugs
		** Description:		looks at which bugs have health <= to 0
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	takes them out of vector
		*********************************************************************/
		void EvaluateBugs();
		/*********************************************************************
		** Function:		AntActions()
		** Description:		Attack for ants.
		** Parameters:		NA
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void AntActions();
		/*********************************************************************
		** Function:		OneRangeAttack
		** Description:		Attacks an ant on a block
		** Parameters:		int block (space of 2d vector)
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		bool OneRangeAttack(int);
		/*********************************************************************
		** Function:		OneRangeAttackALL
		** Description:		Attacks every ant on a block
		** Parameters:		int blockX (space of 2d vector)
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		bool OneRangeAttackALL(int);
		/*********************************************************************
		** Function:		TwoRangeAttack
		** Description:		Attacks every ant for 2 spaces
		** Parameters:		int blockX (space of 2d vector)
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void TwoRangeAttack(int);
		/*********************************************************************
		** Function:		foundBodyguard
		** Description:		Attacks every ant for 4 spaces
		** Parameters:		int blockX (space of 2d vector)
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void FourRangeAttack(int);
		/*********************************************************************
		** Function:		AntBlowsUp
		** Description:		Kills all bees on fire ants block when dead
		** Parameters:		int blockX, block Y (space of 2d vector)
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void AntBlowsUp(int, int);
		/*********************************************************************
		** Function:		ProtectedAttack
		** Description:		gives an extra attack to ants after BodyGuard dies
		** Parameters:		int blockX, blockY (space of 2d vector)
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		void ProtectedAttack(int, int);
		/*********************************************************************
		** Function:		checkforbodyguard
		** Description:		checks for BodyGuard
		** Parameters:		int blockX (space of 2d vector)
		** Pre-Condition:	NA
		** Post Condition:	Na
		*********************************************************************/
		bool checkforbodyguard(int);

};
