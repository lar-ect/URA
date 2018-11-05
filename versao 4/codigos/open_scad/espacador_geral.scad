module suprteSG ()  {

raioMaior = 12;
raioMenor = 3.5; 
altura = 2; 
comprimento = 93; 

module base () {
 
  
 cylinder(altura,raioMaior,raioMaior,true);
 
}

module furosBase() {
 
    cylinder(altura+1,raioMenor,raioMenor,true);
     
 

}

difference(){
base(); 
furosBase();

}

}


projection(cut = false)  suprteSG(); 