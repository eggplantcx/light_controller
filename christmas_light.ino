#include <Pot.h>
#include <Relay.h>

/*     WIRING 
 * Tree1    = R1(2)
 * Tree2    = R2(3)
 * Tree3    = R3(4)
 * Elf1F    = R4(5) NO
 * Elf1B    = R4(5) NC
 * Elf2F    = R4(5) NC
 * Elf2      = R5(6)
 * Elf2B    = R6(7)
 * DeadElf1 = R7(8)
 * DeadElf2 = R8(9)
 */

//Saw attatched to Elf back

#define DELAY_MULTIPLIER 2500

#define TREE1     0 
#define TREE2     1 
#define TREE3     2
/* ELF is Special
 * When disabled Elf1B and Elf2F are on
 * When enabled Elf1F is on
 */
#define ELF       3
//Elf 2 needs to be able to turn off completely
#define ELF2      4
#define ELF2B     5 
#define DEADELF1  6
#define DEADELF2  7

Relay relays[8] = {{2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}};
Pot pot(A5, 512);

unsigned int delayAmount(){ 
  unsigned int result = pot.percent() * DELAY_MULTIPLIER;
  Serial.println(result);
  return result; 
}
 
void elfSaw(unsigned int amount){
  if(amount == 0){ return; }
  relays[ELF].disable(); //Elf1B and Elf2F on
  relays[ELF2B].disable(); //Elf2B off
  relays[ELF2].enable(); //Elf2 on
  for(unsigned int i = 0; i < amount; i++){
    delay(delayAmount());
    relays[ELF].toggle(); //Elf1F on and Elf2F off
    relays[ELF2B].toggle(); //Elf2B toggle
  }  
}

void treeFall(){
  relays[TREE1].disable();
  relays[TREE2].enable();
  relays[ELF2B].disable(); //Elf2B off
  relays[ELF2].disable(); //Elf2 off
  relays[ELF].enable(); //Elf1F on
  delay(delayAmount());
  relays[TREE2].disable();
  relays[TREE3].enable();
}

void deadElf(unsigned int amount){
  if(amount == 0){ return; }
  relays[DEADELF1].enable();
  relays[DEADELF2].disable();
  for(unsigned int i = 0; i < amount-1; i++){
    delay(delayAmount());
    relays[DEADELF1].toggle();
    relays[DEADELF2].toggle();
  }
}

void disableAll(){
  size_t size = sizeof(relays) / sizeof(Relay);
  for(size_t i = 0; i < size; i++){
    relays[i].disable();  
  }
}

void resetRelays(){
  //Tree
  relays[TREE1].enable();
  relays[TREE2].disable();
  relays[TREE3].disable();
  //Elves
  relays[ELF].disable();
  relays[ELF2B].disable();
  relays[ELF2].enable();
  //Dead Elf
  relays[DEADELF1].disable();
  relays[DEADELF2].disable();
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  resetRelays();
  delay(1000);
  elfSaw(6);
  delay(delayAmount());
  treeFall();
  delay(delayAmount()); //Might Not want delay here
  deadElf(5);
  delay(delayAmount()); //Might not need delay here*/
}
