		surface DifSpecAmbControl(
float Kd = .8;
float Ks = 1;
float Ka = 1;
float roughness = 0.1;
color myColor = 1;
color  myOpacity = 1;
color  specularcolor = 1; 
)
{
        //Diffuse stuff
        normal Nn = normalize(N);
        
        //Specular stuff
        vector V = normalize(-I);
        
        
        Ci = myColor * myOpacity * (Kd*diffuse(Nn) + Ka*ambient()) + Ks* specularcolor * specular(Nn, V, roughness);
        Oi = myOpacity;
}