surface
plastico (
        float Ka = 1;
        float Kd =.5;
        float Ks =.5;
        float roughness =.1;
        color specularcolor = 1;)
{
        normal Nf = faceforward (N, I);
        Nf = normalize(Nf);
        vector V = -normalize (I);
        Oi = Os;
        Ci = Os * (Cs * (Ka * ambient () + Kd * diffuse (Nf)) +
             specularcolor * Ks* specular (Nf, V, roughness) );
}