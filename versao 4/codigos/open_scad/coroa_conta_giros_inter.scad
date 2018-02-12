module principal () {

 raioExterno = 31;
 raioCilindroInterno = 15;  
 difference() {
  cylinder(2,raioExterno,raioExterno);
  // faz uma cavidade a cada 
  for ( a = [0:18:359])   
  rotate([0,0,a]) 
  translate([0,23,0]){
   cube([3,8,3]);
  }

 }
 cylinder(9,raioCilindroInterno,raioCilindroInterno);
    
}


module furos () {
   profundidade = 6; 
   for ( a = [0:90:340])   
    rotate([0,0,a]) { 
    //translate([0,19,0]){
    // cylinder(profundidade+4,3,3);
    //}
    translate([0,8,0]){
     cylinder(profundidade+4,1.5,1.5);
    }
   }   
  
  {
   cylinder(profundidade+4,4.5,4.5); 
   cylinder(profundidade,11,11); 
  } 
}



    difference() { 
principal(); 
furos();
    }
   
    
   /* 
    difference() { 
        cylinder(9,23,23);
        
        translate([0,0,-1]){  
            cylinder(7,31,31);
        }
    }

*/