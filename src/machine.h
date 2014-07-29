//
//  EnigmaMachine.h
//  enigma
//
//  Created by Garrett Thornburg on 7/23/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#ifndef __enigma__machine__
#define __enigma__machine__

#include "rotor.h"

namespace Enigma {

  extern MappingColumn INPUT_OUTPUT;
  extern MappingColumn REFLECTOR;

  class Machine {
    public:

      Machine(Rotor r1, Rotor r2, Rotor r3)
        : m_rotor1(r1), m_rotor2(r2), m_rotor3(r3) {}

      //
      // Members
      //
      char convert(char character) {
        if( character < 65 || character > 90 ) {
          std::cout << "Invalid character! Only [A-Z] allowed." << std::endl;
          throw std::exception();
        }
      
        character = m_rotor3.convert( character, INPUT_OUTPUT, m_rotor3.outer() );
        character = m_rotor2.convert( character, m_rotor3.inner(), m_rotor2.outer() );
        character = m_rotor1.convert( character, m_rotor2.inner(), m_rotor1.outer() );

        int reflector_index = char_at( character, m_rotor1.inner() );
        character = REFLECTOR[reflector_index];
        MappingColumn c_reflector = REFLECTOR;
        c_reflector[ reflector_index ] = NullChar;
        
        reflector_index = char_at( character, c_reflector );
        character = m_rotor1.inner()[ reflector_index ];
        character = m_rotor1.convert( character, m_rotor1.outer(), m_rotor2.inner() );
        character = m_rotor2.convert( character, m_rotor2.outer(), m_rotor3.inner() );
        character = m_rotor3.convert( character, m_rotor3.outer(), INPUT_OUTPUT );
        
        m_rotor3.advance_position();

        return character;
      }

      std::string convert_string( std::string str ) {
        MappingColumn mappings;
        mappings.reserve( str.size() );
        for( auto c : str ) {
          mappings.push_back( convert(c) );
        }
        return std::string( mappings.begin(), mappings.end() );
      }

      void reset() {
        m_rotor1.reset_position();
        m_rotor2.reset_position();
        m_rotor3.reset_position();
      }

    private:
      Rotor m_rotor1;
      Rotor m_rotor2;
      Rotor m_rotor3;
  };

}; // Enigma


#endif /* defined(__enigma__machine__) */
