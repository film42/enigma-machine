//
//  EnigmaMachine.cpp
//  enigma
//
//  Created by Garrett Thornburg on 7/23/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#include "machine.h"

namespace Enigma {

  MappingColumn INPUT_OUTPUT = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
  
  MappingColumn REFLECTOR = { 'A','B','C','D','E','F','G','D','I','J','K','G','M','K','M','I','E','B','F','T','C','V','V','J','A','T' };
  
}