#include <iostream>
#include "sports.hpp"

int main()
{
  Athlete athlete[] = {Athlete("Dudley Stokes"), Athlete("Devon Harris"),
                       Athlete("Michael White"), Athlete("Chris Stokes"),
                       Athlete("Takao Sakai"),   Athlete("Toshio Wakita"),
                       Athlete("Yuji Yaku"),     Athlete("Naomi Takewaki"),
                       Athlete("Tai Tzu-ying"),  Athlete("Chen Yufei")};

  Team bobsledding(TEAM_SIZE);
  Competitive badminton;

  // loop through the array of athletes to add them to the bobsledding teams
  for (int i = 0; i < TEAM_SIZE * 2; i++)
  {
    // TODO
    // call the athlete's "join" function to add the current athlete
    // to the bobsledding team
    // hint: do this for the athlete at location i of the array
    athlete[i].join (&bobsledding);

  }
  bobsledding.display();
  std::cout << std::endl;

  // loop through the array of athletes to add them to the badminton competition
  for (int i = TEAM_SIZE * 2; i < (TEAM_SIZE * 2) + 2; i++)
  {
    // TODO
    // call the athlete's "join" function to add the current athlete
    // to the badminton team
    // hint: do this for the athlete at location i of the array
    athlete[i].join (&badminton);

  }
  badminton.display();
  std::cout << std::endl;

  // add one more to each Sport to see the error messages
  bobsledding.enroll("One more");
  badminton.enroll("One more");

  return 0;
}
