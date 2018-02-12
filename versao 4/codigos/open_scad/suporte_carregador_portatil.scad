raioMaior = 12;
raioMenor = 3.5; 
altura = 30; 

comprimento = 93; 

module base () {
 
 translate([-comprimento/2,0,0])
 cube([comprimento,2*raioMaior,altura],true);
 cylinder(altura,raioMaior,raioMaior,true);
 translate([-comprimento,0,0])
    cylinder(altura,raioMaior,raioMaior,true);
}

module furosBase() {
 tam = comprimento*0.7;
 cylinder(altura+1,raioMenor,raioMenor,true); 
 translate([-comprimento,0,0])
    cylinder(altura+1,raioMenor,raioMenor,true); 
    
 translate([-comprimento/2,0,0]) {
  
   espacamento = 5; 
   larguraFuro = 75;
   alturaFuro = altura -4; 
   translate([0,raioMaior/2-1,0])
   cube([larguraFuro - 2*espacamento,40,alturaFuro-2*espacamento],true); 
  
  translate([0, -2,0])
   cube([larguraFuro,2*raioMaior,alturaFuro],true); 
  } 
}

module suporteCarregador() {
 difference(){
  base(); 
  furosBase();
 }
}

rotate([270,0,0])
translate([comprimento/2, 0,0])
suporteCarregador(); 
//
 //base(); 
 //cylinder(altura+1,raioMenor,raioMenor,true); 
//}