largura = 25;
comprimento = 52; 
altura = 11; 
paredeGrossa = 3; 
paredeFina = 2; 


module suporteParafuso () {
 translate([0,0,  + altura/2])
 rotate([90,0,0])
    cylinder($fn=30, comprimento,4,4,true); 
}

module base() {
 suporteParafuso();
 cube([largura,comprimento,altura],true);
    
}

module furos() {
    
 // profundidade superior 
 translate([0,0, (altura-paredeFina)/2])
 cube([largura+1,comprimento-2*paredeGrossa,3],true);
 
 translate([0,0, altura])   
     cube([largura-paredeFina,comprimento-2*paredeGrossa,10],true); 

 

// profundidade principal 
 
 cube([largura-2*paredeFina,comprimento-2*paredeGrossa,7],true);// 7 é a profundidade interna do sensor  


// profundidade inferior
raioB = 10;   
distanciaCentroFuro = 13; 
translate([0,distanciaCentroFuro,0])
 cylinder($fn=20, comprimento+1,raioB,raioB,true);

translate([0,-distanciaCentroFuro,0])
 cylinder($fn=20, comprimento+1,raioB,raioB,true);

 translate([0,0,  altura/2])
 rotate([90,0,0])
 cylinder($fn=20, comprimento+1,1.2,1.2,true);

}



difference(){
base(); 
furos();

}

 
 
 
 