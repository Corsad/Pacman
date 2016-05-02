#ifndef Struct_Entity
#define Struct_Entity

/** Struct for pacman and ghost
  */
struct entity{
	int x;
	int y;
	char replacedChar;
	char type;
	char dir;
};

#define Power 15

#endif