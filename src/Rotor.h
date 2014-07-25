//
//  Rotor.h
//  enigma
//
//  Created by Garrett Thornburg on 7/23/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#ifndef __enigma__Rotor__
#define __enigma__Rotor__

#include <iostream>
#include "types.h"
#include "utils.h"

namespace Enigma {

  // Rotor
  class Rotor {
    public:
    
      Rotor( Mapping mapping, int position ) {
        m_mapping = mapping;
        m_position = position;
        m_starting_position = position;
      }
    
      //
      // Members
      //
      char convert(char character, MappingColumn source, MappingColumn matches) {
      
        int index = char_at(character, source);
        
        return matches[ index ];
      }
    
      MappingColumn outer() {
        MappingColumn column;
        auto it = std::next( m_mapping.begin(), m_position );
        for(;it != m_mapping.end(); ++it) {
          column.push_back( it->second );
        }
        
        return column;
      }
    
      MappingColumn inner() {
        MappingColumn column;
        auto it = std::next( m_mapping.begin(), m_position );
        for(;it != m_mapping.end(); ++it) {
          column.push_back( it->first );
        }
        
        return column;
      }
    
      int position() { return m_position; }
      void reset_position() { m_position = m_starting_position; }
      void advance_position() { ++m_position; }
    
    private:
      Mapping m_mapping;
      int m_starting_position;
      int m_position;
  };

  /*********************
   *  Predefined Rotors *
   *********************/
  extern Mapping ROTOR_I;
  extern Mapping ROTOR_II;
  extern Mapping ROTOR_III;
}; // Enigma

#endif /* defined(__enigma__Rotor__) */
