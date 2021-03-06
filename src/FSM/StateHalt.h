#ifndef STATE_HT
#define STATE_HT

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "State.h"

class StateHalt: public State{

 public:

  StateHalt();

  void Enter();
  void Execute(StateManager * fsm);
  void Exit();
  
  State * Transition(bool* stimuli);

  void Print();
  
  std::string GetNameString();
 
  private:

  string name;

};
#endif
