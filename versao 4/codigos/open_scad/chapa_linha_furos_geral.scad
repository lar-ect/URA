module suprteSG ()  {

raioMaior = 12;
raioMenor = 3.5; 
altura = 2; 
comprimento = 93; 

module base () {
 
 translate([-comprimento/2,0,0])
 cube([comprimento,2*raioMaior,altura],true);
 cylinder(altura,raioMaior,raioMaior,true);
 translate([-comprimento,0,0])
    cylinder(altura,raioMaior,raioMaior,true);
}

module furosBase() {

  for (s = [0:15.5:100]){
     translate([-s,0,0])
    cylinder(altura+1,raioMenor,raioMenor,true);
     
  }  

}

difference(){
base(); 
furosBase();

}

}


projection(cut = false)  suprteSG(); 