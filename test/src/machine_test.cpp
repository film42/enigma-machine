#include "things.h"

using namespace ::testing;

TEST(MachineTest, convert_a_character) {
  Enigma::Rotor rotor1( Enigma::ROTOR_I, 12 );
  Enigma::Rotor rotor2( Enigma::ROTOR_II, 2 );
  Enigma::Rotor rotor3( Enigma::ROTOR_III, 11 );
  Enigma::Machine machine( rotor1, rotor2, rotor3 );

  char res = machine.convert( 'E' );

  EXPECT_EQ( res, 'Q' );
}

TEST(MachineTest, convert_character_in_reverse) {
  Enigma::Rotor rotor1( Enigma::ROTOR_I, 12 );
  Enigma::Rotor rotor2( Enigma::ROTOR_II, 2 );
  Enigma::Rotor rotor3( Enigma::ROTOR_III, 11 );
  Enigma::Machine machine( rotor1, rotor2, rotor3 );

  char res = machine.convert( 'Q' );

  EXPECT_EQ( res, 'E' );
}

TEST(MachineTest, same_char_different_ciphper_when_rotor_moves) {
  Enigma::Rotor rotor1( Enigma::ROTOR_I, 12 );
  Enigma::Rotor rotor2( Enigma::ROTOR_II, 2 );
  Enigma::Rotor rotor3( Enigma::ROTOR_III, 11 );
  Enigma::Machine machine( rotor1, rotor2, rotor3 );

  EXPECT_EQ( machine.convert( 'Q' ) , 'E' );
  EXPECT_EQ( machine.convert( 'Q' ) , 'D' );
  EXPECT_EQ( machine.convert( 'Q' ) , 'Y' );
  EXPECT_EQ( machine.convert( 'Q' ) , 'M' );
}

TEST(MachineTest, encode_string) {
  Enigma::Rotor rotor1( Enigma::ROTOR_I, 12 );
  Enigma::Rotor rotor2( Enigma::ROTOR_II, 2 );
  Enigma::Rotor rotor3( Enigma::ROTOR_III, 11 );
  Enigma::Machine machine( rotor1, rotor2, rotor3 );

  EXPECT_EQ( machine.convert_string("CIDER") , "WFGPF" );

  machine.reset();

  EXPECT_EQ( machine.convert_string("WFGPF") , "CIDER" );
}

TEST(MachineTest, accepts_only_valid_input_A_Z) {
  Enigma::Rotor rotor1( Enigma::ROTOR_I, 12 );
  Enigma::Rotor rotor2( Enigma::ROTOR_II, 2 );
  Enigma::Rotor rotor3( Enigma::ROTOR_III, 11 );
  Enigma::Machine machine( rotor1, rotor2, rotor3 );

  EXPECT_THROW( machine.convert(' '), std::exception );
  EXPECT_THROW( machine.convert('a'), std::exception );
  EXPECT_THROW( machine.convert('\0'), std::exception );
  EXPECT_THROW( machine.convert_string("TEST "), std::exception );
}
