
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


char *Currpos;

int eval_sirasi = 0;

int var_num;

char** map;

char* tekrarli_char_arr;


char *inputString(){
    
    char* result;
    int counter = 0;
    char curr_char;
    
    result = (char*) malloc(20 * sizeof(char));
    
    while(1){

        curr_char = getchar();

        if(curr_char == EOF){

            break;
        }

        /* EOF olmadigi surece aliyrouz */

        else if(!isspace(curr_char)){
            char* wtf;

            /* bosluk degilse aliyoruz */

            counter++;

            wtf = (char *) realloc(result, sizeof(char)*(counter+20));
        if(wtf){result = wtf;}
            result[counter-1] = curr_char;

        }
        
    }

    return(result);    

}


int var_sirasi(char* array, char ch, int size)

{
    int i;
    
    for(i=0; i<size ; i++){

        if(array[i] == ch){

            return(i);
        }

    }
    return 0;

}

int read_and_eval_from_currpos(){
    
    int left, right;
    
    char operatorsa;
    
    if(*Currpos == '('){
        
        Currpos++;
        
        left = read_and_eval_from_currpos();
        
        operatorsa = *Currpos++;
        
        right = read_and_eval_from_currpos();

        Currpos++;
        
        while(*Currpos == ' '){
            
            Currpos++;
            
        }
        
        if(operatorsa == '&'){
            
            return(left && right);
        }
        
        if(operatorsa == '|'){
            
            return(left || right);
        }
        
        if(operatorsa == '>'){
            
            return( !(left > right) );
        }
        
        if(operatorsa == '='){
            
            return(left == right);
        }
        else{return 0;}
        
    }
    
    else if(*Currpos == '-'){
            
        Currpos++;
        
        return(!read_and_eval_from_currpos());
            
        }
        
    else if(*Currpos == ' '){
        
        Currpos++;
        
        return(read_and_eval_from_currpos());
        
    }
    else if(*Currpos == ')'){
    
    Currpos++;
    return(read_and_eval_from_currpos());
    }
    
        
    
    
    else{

        char tempo;
        char anan;
        sscanf(Currpos,"%c", &tempo);
        anan = map[eval_sirasi][var_sirasi(tekrarli_char_arr, tempo, var_num)];

        if(anan == 'T'){

            left = 1;
        }

        else if(anan == 'F'){

            left = 0;  

        }

        Currpos++;
        
        while(*Currpos == ' '){
            Currpos++;
        }
        
        return(left);
            
        }
    }


int the_real_eval(char* input){

    Currpos = input;
    return read_and_eval_from_currpos();


}

int main() {

    char* input;
    
    int i;
    
    int counter=0;
        
    int index=0;
    
    
    int j,n;
    
    int k;
    
    int number;
    
    char temp;

    int R;


input = inputString();

Currpos = input;

for(i=0; input[i]!='\0' ;i++){
    
    if(islower(input[i])){
        
        counter++;
        
    }
    
}


tekrarli_char_arr = (char*) malloc(counter*sizeof(char));


for(i=0; input[i]!='\0' ;i++){
    
    if(islower(input[i])){
        

        
        tekrarli_char_arr[index] = input[i];
        
        index++;
        
    }
    
}





number = index;





for(i=0;i<number;i++){
    for(j = i+1; j < number; j++){
        if(tekrarli_char_arr[i] == tekrarli_char_arr[j]){
            for(k = j; k <number; k++){
                tekrarli_char_arr[k] = tekrarli_char_arr[k+1];
                }          j--;          number--;       }    } }




   
   n = number;
   

   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (tekrarli_char_arr[i] > tekrarli_char_arr[j]) {
            temp = tekrarli_char_arr[i];
            tekrarli_char_arr[i] = tekrarli_char_arr[j];
            tekrarli_char_arr[j] = temp;
         }
      }
   }




/* Artik  tekrarli_char_arr dedigimiz array alfabetik order a gore dizili */
     
     
     
     var_num = number;
     
     
    map = (char**) malloc(sizeof(char*)*pow(2, var_num));
    
    for(i=0; i<pow(2,var_num); i++)
    {
        map[i] = (char*) malloc(sizeof(char)*var_num);
    }
    for(i=0; i<pow(2, var_num); i++)
    {
        for(j=0; j<var_num; j++)
        {
            int anan = !((i/(int) pow(2, (var_num - (j+1))))%2);
            if(anan)
            {
                map[i][j] = 'T';
            }
            else
            {
                map[i][j] = 'F';
            }
        }
    }
    


   /*buraya printler basliyacak a b c d k R print edilecek*/

    for(i=0; i < var_num ;i++){

        printf("%c ", tekrarli_char_arr[i]);


    }

    printf("R\n");



    for(i=0; i<pow(2, var_num) ;i++){


        for(j=0; j < var_num ;j++){

            printf("%c ", map[i][j]);

        }


        /*char ** map, char* alf_ordered_arr, int size*/

        R = the_real_eval(input);


        if(R == 1){

            printf("T\n");

        }

        else if(R == 0){

            printf("F\n");

        }

        /* map[i] --> read_and_eval_from_currpos() */

        eval_sirasi++;
        
    }
       
     
     
     
    
    
    return 0;
}



