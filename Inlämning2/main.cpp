#include "PhysicalMove.h"
#include "SpecialMove.h"
#include "DualTypePokemon.h"

void main() {
	PhysicalMove quickAttack("Quick Attack", NORMAL, 70);
	SpecialMove swift("Swift", NORMAL, 60);
	PhysicalMove ironTail("Iron Tail", STEEL, 100);
	SpecialMove thunder("Thunder", ELECTRIC, 110);
	SpecialMove shadowBall("Shadow Ball", GHOST, 80);
	PhysicalMove payback("Payback", DARK, 50);
	PhysicalMove earthquake("Earthquake", GROUND, 100);

	Pokemon* pikachu = new Pokemon("Pikachu", ELECTRIC, &quickAttack, &swift, &ironTail, &thunder, 30, 90, 90, 60, 50);
	Pokemon* gengar = new DualTypePokemon("Gengar", POISON, GHOST, &thunder, &shadowBall, &payback, &earthquake, 40, 80, 100, 80, 80);

	//utskrifterna kan skiljas beroende på formel för damage.

	pikachu->executeMove1(gengar);
	// Pikachu used Quick Attack.
	// It doesn't affect Gengar.
	gengar->executeMove1(pikachu);
	// Gengar used Thunder.
	// It's not very effective...
	pikachu->executeMove2(gengar);
	// Pikachu used Swift.
	// It doesn't affect Gengar.
	gengar->executeMove2(pikachu);
	// Gengar used Shadow Ball.
	pikachu->executeMove3(gengar);
	// Pikachu used Iron Tail.
	gengar->executeMove3(pikachu);
	// Gengar used Payback.
	pikachu->executeMove4(gengar);
	// Pikachu used Thunder.
	gengar->executeMove4(pikachu);
	// Gengar used Earthquake.
	// It's super effective!
	pikachu->executeMove3(gengar);
	// Pikachu used Iron Tail.
	gengar->executeMove4(pikachu);
	// Gengar used Earthquake.
	// It's super effective!
	// Pikachu fainted.
	pikachu->executeMove3(gengar);
	// Pikachu is in a fainted state and can't move.
	gengar->executeMove4(pikachu);
	// Gengar cannot perform the move, Pikachu has already fainted.

	delete pikachu;
	delete gengar;
}







