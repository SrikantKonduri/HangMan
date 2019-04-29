#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int string_no=0;
char get_input(char *s,int *lifes){
   if(*lifes==0){printf("You Lose Not Enough Lives\n");return;}
   char ch;
   printf("\t\t\t\t\t\tGive a guess- lifes:%d\n",*lifes);
   *s=getchar();
   fflush(stdin);
   return *s;
}

int reveal_wantedLetter(char *s,char *mainString,char _input){
   int count=0;
   for(int i=0;i<strlen(s);i++){
      if(s[i]=='_'){
         if(_input==mainString[i]){s[i]=_input;return 1;}
         else{return 0;}
      }
   }
}

int check_vowel(char ch){
   if(ch=='a' || ch=='e' ||ch=='i'||ch=='o'||ch=='u'){
      return 1;
   }
   return 0;
}
void print_word(char *s,int *lifes_count,char *mainString){
   system("cls");
   char *letter=(char *)malloc(sizeof(char));
   printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t------HANGMAN--------");
   printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tQuestion: %s\n",s);
   char ch=get_input(letter,lifes_count);
   int countOf_=0;
   for(int i=0;i<strlen(s);i++){
      if(s[i]=='_'){countOf_++;}
   }
   while(*lifes_count>=1 && countOf_>0){
      if(check_vowel(ch)){
         if(!reveal_wantedLetter(s,mainString,ch)){*lifes_count -=1;}
         else{countOf_--;}
      }
      else{
         *lifes_count -=1;
      }
      system("cls");
      printf("Question: %s\n",s);
      *letter='\0';
      if(*lifes_count==0){printf("You Lose the match Not Enough lifes!!\n");exit(0);}
      if(countOf_==0){printf("You Win! Press Enter to Continue\n");}
      ch=get_input(letter,lifes_count);
   }

}

void hide_vowels(char *word){
   char *main_string=(char *)malloc((strlen(word)+1)*sizeof(char));
   strcpy(main_string,word);
   for(int i=0;i<strlen(word);i++){
      if(check_vowel(word[i])){
         word[i]='_';
      }
   }
   int lives=5;
   print_word(word,&lives,main_string);
}
void playgame(char *words,int words_len){
   char *partial_string=(char *)malloc((words_len+1)*sizeof(char));
   strcpy(partial_string,words);
   hide_vowels(partial_string);
}
void start(){
   FILE *fp;
   fp=fopen("file.txt","r");
   char *s=(char *)malloc(256*sizeof(char));
   while(fscanf(fp,"%s",s)!=EOF){
      playgame(s,strlen(s));
   }
}

int main(){
   start();
}
