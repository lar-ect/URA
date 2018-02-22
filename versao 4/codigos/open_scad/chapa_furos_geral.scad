module chapaSG (qtX,qtY)  {

raioMaior = 12;
raioMenor = 3.5; 
altura = 2; 
    
//qtX = 7;
//qtY = 4;  
    
distFuros = 15.5; 

comprimento = (qtX-1)*distFuros+2*raioMaior;
   
largura = (qtY-1)*distFuros+2*raioMaior;

module base(){
 
 translate([-comprimento/2,largura/2,0])
 cube([comprimento,largura,altura],true);
    
 //cylinder(altura,raioMaior,raioMaior,true);
    
 //translate([-comprimento,0,0])
 //   cylinder(altura,raioMaior,raioMaior,true);
}

module furosBase() {

for(sY = [raioMaior:distFuros:distFuros*qtY])
  for (sX = [raioMaior:distFuros:distFuros*qtX]){
     translate([-sX,sY,0])
    cylinder(altura+1,raioMenor,raioMenor,true);
     
  } 
    

}

difference(){
base(); 
furosBase();

}

}


projection(cut = false)  chapaSG(3,4); 
