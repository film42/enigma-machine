//
//  utils.cpp
//  enigma
//
//  Created by Garrett Thornburg on 7/24/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#include "utils.h"

int char_at( char character, MappingColumn source ) {
  auto it = std::find(source.begin(), source.end(), character);
  int index = (int)( it - source.begin() );
  
  if( it == source.end() ) {
    std::cout << "No valid char " << character << " found." << std::endl;
    throw std::exception();
  }
  
  return index;
}
