// FileName  : team.h
// programmer : J. Marron
// definition of the team struct
#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <string>

using namespace std;

struct team
{
	public:
	string teamName;
	int win;
	int loss;
	int tie;
	double pct;
	int hwin, hloss, htie;
	int rwin, rloss, rtie;
	int dwin, dloss, dtie;
	int div;

};
#endif