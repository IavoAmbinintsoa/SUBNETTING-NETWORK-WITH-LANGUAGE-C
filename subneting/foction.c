#include "subnet.h"

void divisionSR(char *IP,int netmask) {
    printf("===================================\n");    
    int decoupage;
    unsigned int ip, subnet_size;
    unsigned int i, network, broadcast;
    char *IPReseau;
    char *Broad;
    int tempnetmask = netmask;
    int new_prefix_length;
    int subnet_count;
    ip = int_Ip(IP);
    netmask = (tempnetmask == 0) ? 0 : (~0 << (32 - tempnetmask));
    printf("Combien de decoupages souhaitez-vous ? ");
    scanf("%d", &decoupage);
    subnet_count = pow(2,decoupage);  
    new_prefix_length = tempnetmask + decoupage;
    if (new_prefix_length > 32) {
        printf("Le nombre de decoupages est trop grand pour cette adresse IP.\n");
        return;
    }
    subnet_size = pow(2,32- new_prefix_length);
    printf("\n===================================================\n");
    printf("[\t\t  Reseau | \t\tBroadcast]\n");
    printf("===================================================\n");
    printf("machine = %u\n",subnet_size);
    for (i = 0; i < subnet_count; i++) {
        network = (ip & netmask) + (i * subnet_size);
        broadcast = network + subnet_size - 1;
        IPReseau = charIp(network);
        Broad = charIp(broadcast);
        printf("[%d) %20s | %22s]\n",i+2,IPReseau,Broad);
    }
}
unsigned int int_Ip(char *IP)
{
    unsigned int octect1,
        octect2,
        octect3,
        octect4;
    sscanf(IP,"%u.%u.%u.%u",&octect1,&octect2,&octect3,&octect4);
    return (octect1 << 24) | (octect2 << 16) | (octect3 << 8) | octect4;
}
char *charIp(int ip) {
        char *IP = malloc(sizeof(char)*32);
    int octect1 = (ip >> 24) & 0xFF,
        octect2 = (ip >> 16) & 0xFF,
        octect3 = (ip >> 8) & 0xFF,
        octect4 = ip & 0xFF;
    sprintf(IP,"%d.%d.%d.%d",octect1,octect2,octect3,octect4);
    return IP;
}
//-------------------//
int *fillmasque(int netmask)
{
    int *mask = malloc(sizeof(int)*9);
    int i;
    for(i = 0;i < 8;i++)
    {  
        if(i < netmask)
            mask[i] = 1;
        else
            mask[i] = 0;
    }
    return mask;
}
void test_adress()
{
    char *IP = (char*)malloc(sizeof(char)*40);
    do
    {
        printf("Entrer l'adress IP (X.X.X.X/netmask): ");
        fgets(IP,35,stdin);
        IP[strcspn(IP, "\n")] = '\0';
    } while (!verify(IP));    
    detail_of_IP(IP);
    free(IP);
}
void detail_of_IP(char *IP)
{
    int octect1,octect2,octect3,octect4,netmask;
    int *reste = malloc(sizeof(int)*9);
    int *masque1;
    int *masque2;
    int *masque3;
    int *masque4;
    int bytes1;
    int bytes2;
    int bytes3;
    int bytes4;
    char *adresse_broadcast;
    int tempnetmask;
    char *adresse_reseau;
    int nombredemachine;
    sscanf(IP,"%d.%d.%d.%d/%d",&octect1,&octect2,&octect3,&octect4,&netmask);
    tempnetmask = netmask;
    masque1 = fillmasque(netmask);
    netmask -= 8;
    masque2 = fillmasque(netmask);
    netmask -= 8;
    masque3 = fillmasque(netmask);
    netmask -= 8;
    masque4 = fillmasque(netmask);
    //==============================================//
    bytes1 = IPReseau(octect1,masque1);
    bytes2 = IPReseau(octect2,masque2);
    bytes3 = IPReseau(octect3,masque3);
    bytes4 = IPReseau(octect4,masque4);
    nombredemachine = (pow(2,(32-tempnetmask)))-2;
    adresse_reseau = cat(bytes1,bytes2,bytes3,bytes4);
    bytes1 = broadcast(octect1,masque1);
    bytes2 = broadcast(octect2,masque2);
    bytes3 = broadcast(octect3,masque3);
    bytes4 = broadcast(octect4,masque4);
    adresse_broadcast = cat(bytes1,bytes2,bytes3,bytes4);
    printf("\n=========================================\n");
    printf("=>ADRESSE IP : %s\n",IP);
    printf("=>Adresse reseau      : %s\n",adresse_reseau);
    printf("=>Adresse broadcast   : %s\n",adresse_broadcast);
    printf("=>Nombre de machine   : %d\n",nombredemachine);
    printf("\n=========================================\n");
    divisionSR(IP,tempnetmask);
}
char *cat(int a,int b,int c,int d)
{
    char *retour = malloc(sizeof(int)*32);
    sprintf(retour,"%d.%d.%d.%d",a,b,c,d);
    return retour;
}
int IPReseau(int octet,int* masque) {
    int* bin = to_binary(octet);
    int resultat = 0;
    int i;
    for (i = 0; i < 8; i++) {
        if (bin[i] & masque[i]) {
            resultat |= (1 << (7 - i));
        }
    }
    free(bin);
    return resultat;
}
int broadcast(int octect,int *masque)
{
{
    int * octect1 = to_binary(octect);
    int resultat[8];
    int i;
    for(i = 0;i < 8;i++)
    {
        if(masque[i] == 1)
            masque[i] = 0;
        else if (masque[i] == 0)
        {
            masque[i] = 1;
        }
    }
    for (i = 0; i < 8; i++)
    {
        resultat[i] = octect1[i]|masque[i];
    }//00001011
    int resultatint = 0;
    for (i = 0; i < 8; i++)
    {
        resultatint += resultat[i]*pow(2,7-i);
    }
    return resultatint;
}
}
int *to_binary(int a)
{
    int * bin = malloc(sizeof(int)*10);
    int tempbin[10];
    int temp = a,
                i,
                j;
    for(i = 0;temp != 0;i++){
        tempbin[i] = temp%2;
        temp /= 2;
    }
    if(i < 8)
    {
        for(j = i;j < 8;j++)
        {
            tempbin[j] = 0;
        }
    }
    for(j = 0;j < 8;j++)
    {
        bin[j] = tempbin[8 - j - 1];
    }
    return bin;
}
bool verify(char *IP)
{
    int octect1;
    int octect2;
    int octect3;
    int octect4;
    int netmask;
    int verification;
    verification = sscanf(IP,"%d.%d.%d.%d/%d",&octect1,&octect2,&octect3,&octect4,&netmask);
    if(verification != 5)
        return false;
    if(!validbytes(octect1) || !validbytes(octect2) || !validbytes(octect3) || !validbytes(octect4))
        return false;
    return true;
}
bool validbytes(int byte)
{
    if(byte > 255 || byte < 0)
        return false;
    return true;
}