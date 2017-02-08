/*
 * Include the provided hashtable library
 */
#include "hashtable.h"

/*
 * Include the header file
 */
#include "philspel.h"

/*
 * Standard IO and file routines
 */
#include <stdio.h>

/*
 * General utility routines (including malloc())
 */
#include <stdlib.h>

/*
 * Character utility routines.
 */
#include <ctype.h>

/*
 * String utility routine
 */
#include <string.h>

/*
 * this hashtable stores the dictionary
 */
HashTable *dictionary;

/*
 * the MAIN routine.  You can safely print debugging information
 * to standard error (stderr) and it will be ignored in the grading
 * process in the same way which this does.
 */
int main(int argc, char **argv){
  if(argc != 2){
    fprintf(stderr, "Specify a dictionary\n");
    return 0;
  }
  /*
   * Allocate a hash table to store the dictionary
   */
  fprintf(stderr, "Creating hashtable\n");
  dictionary = createHashTable(2255, &stringHash, &stringEquals);

  fprintf(stderr, "Loading dictionary %s\n", argv[1]);
  readDictionary(argv[1]);
  fprintf(stderr, "Dictionary loaded\n");

  fprintf(stderr, "Processing stdin\n");
  processInput();

  /* main in C should always return 0 as a way of telling
     whatever program invoked this that everything went OK
     */
  return 0;
}

/*
 * You need to define this function. void *s can be safely casted
 * to a char * (null terminated string) which is done for you here for
 * convenience.
 */
unsigned int stringHash(void *s){
    /// hash function from this source
    //www.codereview.stackexchange.com/questions/85556/simple-string-hashing-algorithm-implementation
    if (s == NULL) {
        return 0;
    }

    unsigned hash = 0;
    while (*s != '\0') {
        char c = *s++;
        int a = c - '0';
        hash = (hash * 10) + a;     
    } 
    return hash;
  //char *string = (char *) s;
  //int *size = strlen(string);
  //return supefasthash();
  //fprintf(stderr,"Need to define stringHash\n");
  //exit(0);
}

/*
 * You need to define this function.  It should return a nonzero
 * value if the two strings are identical (case sensitive comparison)
 * and 0 otherwise.
 */
int stringEquals(void *s1, void *s2){
  char *string1 = (char *) s1;
  char *string2 = (char *) s2;
  
  if strcmp(string1, string2){
        return 0
  }
  else{
        return 1
  }
  //fprintf(stderr,"Need to define stringEquals\n");
  //exit(0);
}

/*
 * this function should read in every word in the dictionary and
 * store it in the dictionary.  You should first open the file specified,
 * then read the words one at a time and insert them into the dictionary.
 * Once the file is read in completely, exit.  You will need to allocate
 * (using malloc()) space for each word.  As described in the specs, you
 * can initially assume that no word is longer than 70 characters.  However,
 * for the final 20% of your grade, you cannot assumed that words have a bounded
 * length.  You can NOT assume that the specified file exists.  If the file does
 * NOT exist, you should print some message to standard error and call exit(0)
 * to cleanly exit the program. Since the format is one word at a time, with
 * returns in between, you can
 * safely use fscanf() to read in the strings.
 */
void readDictionary(char *filename){
  char word[70];
  FILE *fin;
  fin *fopen(filename, "r");
  if (fin != NULL){
    fscanf(fin, "%s", word)
    while (word != EOF){
        int size=(strlen(input)+1)*sizeof(char)
        char * newWord =(char *)malloc(size)
        strcpy(newWord, word);
        
        free(newWord)
    }
    fclose(filename)
  }
  else{
        printf("NO file found")
  
  }


  //free old
  //realoc 
  
  //fprintf(stderr,"Need to define readDictionary\n");
  //exit(0);
}


/*
 * This should process standard input and copy it to standard output
 * as specified in specs.  EG, if a standard dictionary was used
 * and the string "this is a taest of  this-proGram" was given to
 * standard input, the output to standard output (stdout) should be
 * "this is a teast [sic] of  this-proGram".  All words should be checked
 * against the dictionary as they are input, again with all but the first
 * letter converted to lowercase, and finally with all letters converted
 * to lowercase.  Only if all 3 cases are not in the dictionary should it
 * be reported as not being found, by appending " [sic]" after the
 * error.
 *
 * Since we care about preserving whitespace, and pass on all non alphabet
 * characters untouched, and with all non alphabet characters acting as
 * word breaks, scanf() is probably insufficent (since it only considers
 * whitespace as breaking strings), so you will probably have
 * to get characters from standard input one at a time.
 *
 * As stated in the specs, you can initially assume that no word is longer than
 * 70 characters, but you may have strings of non-alphabetic characters (eg,
 * numbers, punctuation) which are longer than 70 characters. For the final 20%
 * of your grade, you can no longer assume words have a bounded length.
 */
void processInput(){
  //fprintf(stderr,"Need to define processInput\n");
  //exit(0);
}
