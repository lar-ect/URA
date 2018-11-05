raioMaior = 12;
raioMenor = 3.3; 
altura = 2; 

comprimento = 25; 

module base () {
 
 translate([-comprimento/2,0,0])
 cube([comprimento,2*raioMaior,altura],true);
 cylinder(altura,raioMaior,raioMaior,true);
}

module furosBase() {
 tam = comprimento*0.6;
 cylinder(altura+1,raioMenor,raioMenor,true); 
    
 translate([-tam,0,0]) {
  cube([tam,3.3,altura+1],true);
  translate([0,raioMaior-5,0])
   cube([tam,3.3,altura+1],true); 
  
  translate([0,-raioMaior+5,0])
   cube([tam,3.3,altura+1],true); 
  } 
}

difference(){
base(); 
furosBase();

}
//
 //base(); 
 //cylinder(altura+1,raioMenor,raioMenor,true); 
//}