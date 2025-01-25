//
// Created by bulbasaur on 25/1/25.
//


void kernel_main(){
  char* memory = (char*)0xB8000;
  *memory = 'a';
  while(1){}
}