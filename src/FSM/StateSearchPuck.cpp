#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "StateSearchPuck.h"
#include "FSM.h"

StateSearchPuck::StateSearchPuck(){
 name = "SearchPuck"; 

 /* initialize random seed: */
 srand (time(NULL));
};

void StateSearchPuck::Enter(){};

void StateSearchPuck::Execute(StateManager * fsm){
  //printf("Executing behaviour %s...\n", name.c_str());

    fsm->SetTransSpeed(1);

    if(rand() / (float)RAND_MAX < 0.1){
      fsm->SetRotSpeed(10.*(rand() / (float)RAND_MAX - 0.5));
    }
};

void StateSearchPuck::Exit(){};

State * StateSearchPuck::Transition(bool* stimuli){

  if(stimuli[6] == true){
    return new StateEvade();
  }
  else if(stimuli[0] == true and stimuli[1] == false){
    return new StateTrackPuck();
  }
  else{
    return NULL;
  }
  
};

std::string StateSearchPuck::GetNameString(){
  return name;
};

void StateSearchPuck::Print(){
  printf("%s\n",name.c_str());
};