#include "things.h"

using namespace ::testing;

Mapping mapping = { {'L', 'V'}, {'M', 'Z'} };
MappingColumn io = { 'A', 'B', 'C', 'D' };

TEST(RotorTest, default_rotors_are_size_52) {

  EXPECT_EQ( 52, Enigma::ROTOR_I.size() );
  EXPECT_EQ( 52, Enigma::ROTOR_II.size() );
  EXPECT_EQ( 52, Enigma::ROTOR_III.size() );

}

TEST(RotorTest, convert_correct_character_when_inbound) {

  Enigma::Rotor rotor( mapping, 0 );
  char res = rotor.convert( 'A', io, rotor.outer() );

  EXPECT_EQ( res, 'V' );

}

TEST(RotorTest, conver_correct_character_when_outbound) {

  Enigma::Rotor rotor( mapping, 0 );
  char res = rotor.convert( 'V', rotor.outer(), io );

  EXPECT_EQ( res, 'A' );

}

TEST(RotorTest, should_accept_a_default_position) {

  Enigma::Rotor rotor( mapping, 5 );

  EXPECT_EQ( rotor.position(), 5 );

}
