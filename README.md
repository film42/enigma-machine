Enigma Machine
----------------------

This is a Nazi Enigma Machine, based pretty heavily on @JordanHatch's version in ruby (consider this a port), which can be found here: https://github.com/JordanHatch/enigma-machine. I hope you enjoy your trip through time!

## Usage

```c++
Enigma::Rotor rotor1( Enigma::ROTOR_I, 12 );
Enigma::Rotor rotor2( Enigma::ROTOR_II, 2 );
Enigma::Rotor rotor3( Enigma::ROTOR_III, 11 );
Enigma::Machine machine( rotor1, rotor2, rotor3 );

machine.convert_string("CIDER"); //=> "WFGPF"

machine.reset();

machine.convert_string("WFGPF"); //=> "CIDER"

```

## Compiling

To compile and run the test suite, make sure you have the latest gmock (currently version 1.7.0) in the same directory as the project folder.

To install gmock, download it from google code, extract the latest zip, and inside run: `cmake .`, followed by `make`. It should succeed.

Now that gmock is built, `cd` into the `test` directory and run `cmake .`.

## License
None
