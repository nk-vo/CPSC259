/*
 File:        dna.c
 Purpose:     Consumes a formatted DNA sequence file
              to determine which of a group of candidate
              sequences of nucleotides best matches a
              specified sample.  The formatted DNA
              sequence file is a txt file (threes samples
              are provided in the Resource Files folder).
 Author:			Your names
 Student #s:	12345678 and 12345678
 CS Accounts:	a1a1 and b2b2
 Date:				Add the date here
 */

 /******************************************************************
  PLEASE EDIT THIS FILE

  You need to complete the analyze_segments and calculate_score
  functions.

  You need to understand the entire program

  Comments that start with // should be replaced with code
  Comments that are surrounded by * are hints
  ******************************************************************/

  /* Preprocessor directives */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "dna.h"

int calculate_score(char* sample_segment, char* candidate_segment);

/*
 * Determines if the specified molecules (chars) are a base pair
 * PARAM:     a char
 * PARAM:     a char
 * PRE:       molecule is an alphanumeric ascii char
 * RETURN:    IF nucleotide_1 == nucleotide_2
 *			  THEN 1
 *            ELSE 0
 */
int is_base_pair(char nucleotide_1, char nucleotide_2)
{
  switch (nucleotide_1)
  {
  case 'A': case 'a':
    if (nucleotide_2 == 'T' || nucleotide_2 == 't')
      return 1;
    break;
  case 'T': case 't':
    if (nucleotide_2 == 'A' || nucleotide_2 == 'a')
      return 1;
    break;
  case 'C': case 'c':
    if (nucleotide_2 == 'G' || nucleotide_2 == 'g')
      return 1;
    break;
  case 'G': case 'g':
    if (nucleotide_2 == 'C' || nucleotide_2 == 'c')
      return 1;
    break;
  default:
    return 0;
    break;
  }
  return 0;
}

/*
 * Acquires and returns the specified codon code's index from the
 * codon_codes 2D array in the header file.
 *
 * PARAM:     A pointer to a sequence of characters
 * PRE:       Valid pointer to a sequence of 3 characters.
 * RETURN:    IF the specified codon_code is in the codon_codes 2D array in the header file
 *            THEN returns the index of the specified codon_code in the codon_codes 2D array
 *            ELSE -1
 */
int get_codon_index(char* codon_code)
{
  int i;
  for (i = 0; i < NUMBER_OF_CODONS; ++i) {

    if (codon_codes[i][0] == codon_code[0] &&
      codon_codes[i][1] == codon_code[1] &&
      codon_codes[i][2] == codon_code[2]) {
      return i;
    }
  }
  return -1;
}



/*
 * Extracts the DNA segment information stored in a correctly formatted file.
 *
 * This function does not copy newline characters, but it does append a terminating
 * null character to the end of each DNA segment stored in the heap.  This lets us
 * use functions from string.h (like strncmp and strlen) to process the DNA segments.
 *
 * PARAM:     Pointer to a filestream to copy to main memory
 * PARAM:     Double pointer to the sample segment
 * PARAM:     Triple pointer to a collection of candidate segments
 * PRE:       All the pointers are valid
 * POST:      sample_segment now points to dynamically allocated memory that
 *            contains the sample DNA sequence extracted from the specified file
 * POST:      candidate_segments now points to dynamically allocated memory that
 *            contains the candidate DNA sequences extracted from the specified file
 * RETURN:    the number of candidate_segments extracted from the specified file
 */
int extract_dna(FILE* file_pointer, char** sample_segment, char*** candidate_segments)
{
  /* Variables */
  int  i = 0, j = 0;
  int  return_value = 0;
  int  new_line = 0;
  int  line_length = 0;
  int  sequence_length = 0;
  int  number_of_candidates = 0;
  char character = ' ';
  char line_buffer[BUFSIZE];

  /* Moves to the beginning of the file */
  fseek(file_pointer, 0, SEEK_SET);

  /* Here's an easy way to ignore the first line (the header)! */
  while ((character = fgetc(file_pointer)) != '\n') { ; }

  /* Acquires sample sequence (we know it's in the second line) */
  while (new_line == 0 && fgets(line_buffer, BUFSIZE, file_pointer)) {

    /* Check if the line ends with a newline character and increments the sample length */
    if (line_buffer[strlen(line_buffer) - 1] == '\n') {
      new_line = 1;
      line_length = strlen(line_buffer) - 1;
    }
    else {
      line_length = strlen(line_buffer);
      new_line = 0;
    }

    /* (Re)allocates some space for the (additional) nucleotides */
    *sample_segment = (char*)realloc(*sample_segment, sizeof(char) * (sequence_length + line_length));

    /* Copies the contents of the line buffer to the end of the dynamically (re)allocated memory */
    for (i = 0; i < line_length; ++i) {
      *(*sample_segment + sequence_length + i) = line_buffer[i];
    }
    sequence_length += line_length;
  }

  /* Adds terminating null character to sample, so we can treat it as a null-terminated string */
  *sample_segment = (char*)realloc(*sample_segment, sizeof(char) * (sequence_length + 1));
  *(*sample_segment + sequence_length) = '\0';

  /* Acquires number of candidate sequences (from the third line of the file) */
  fgets(line_buffer, BUFSIZE, file_pointer);
  return_value = sscanf(line_buffer, "%d", &number_of_candidates);

  /* Allocates pointers for correct number of candidate sequences */
  *candidate_segments = (char**)malloc(sizeof(char*) * number_of_candidates);
  for (i = 0; i < number_of_candidates; ++i) {
    *(*candidate_segments + i) = NULL; /* What happens if we omit this line? */
  }

  /* Copies each candidate sequence, in order, from the file to the memory we just
     dynamically allocated */
  for (i = 0; i < number_of_candidates; ++i) {

    sequence_length = 0; /* Resets the variable */
    new_line = 0; /* Resets the variable */

    /* Here's an easy way to ignore each candidate sequence's header */
    while ((character = fgetc(file_pointer)) != '\n') { ; }

    /* Acquires candidate sequence */
    while (new_line == 0 && fgets(line_buffer, BUFSIZE, file_pointer)) {

      /* Check if the line ends with a newline character and sets length */
      if (line_buffer[strlen(line_buffer) - 1] == '\n') {
        new_line = 1;
        line_length = strlen(line_buffer) - 1;
      }
      else {
        line_length = strlen(line_buffer);
        new_line = 0;
      }

      /* (Re)allocates some space for the (additional) nucleotides */
      *(*candidate_segments + i) = (char*)realloc(*(*candidate_segments + i), sizeof(char) * (sequence_length + line_length));

      /* Copies the contents of the line buffer to the end of the dynamically (re)allocated memory */
      for (j = 0; j < line_length; ++j) {
        *(*(*candidate_segments + i) + sequence_length + j) = line_buffer[j];
      }
      sequence_length += line_length;
    }

    /* Adds terminating null character to candidate, so we can treat it as a null-terminated string */
    *(*candidate_segments + i) = (char*)realloc(*(*candidate_segments + i), sizeof(char) * (sequence_length + 1));
    *(*(*candidate_segments + i) + sequence_length) = '\0';
    new_line = 0;
  }

  return number_of_candidates;
}

/*
 * Analyzes the segments.  This is a simple and straight-forward algorithm which does
 * not include any optimization, except that it returns immediately if a perfect match is found.
 *
 * This function must do these things (though not necessarily in this order):
 *
 * a) Check if any candidate segments are perfect matches, and if so, report
 *    all of the perfect matches (and do nothing else) using a message of this format:
 *    "Candidate number %d is a perfect match\n" where %d is the candidate
 *    segment's number in its sample file, then return from the function
 * b) If no perfect matches are found, then find a best match using
 *    the scoring method described in the lab specification
 * c) After a best match is found, the scores for ALL of the candidates that are best
 *    matches is printed out and formatted like this:
 *    ("Candidate number %d matched with a best score of %d\n") where %d is the
 *    candidate segment's number in its sample file
 *
 * Note that reporting is NOT performed using printf.
 * Send the formatted output to a string buffer using strcat
 * Example is given in a comment below.
 *
 * PARAM:     pointer to the sample segment
 * PARAM:     pointer to the candidate segments
 * PARAM:     the number of candidate segments
 * PARAM:     buffer for the complete formatted output string
 * PRE:       pointers are valid pointers to dynamically allocated and populated memory
 * PRE:       number_of_candidates correctly reports the number of candidate sequences
 * POST:      NULL
 * RETURN:    VOID
 */
void analyze_segments(char* sample_segment, char** candidate_segments, int number_of_candidates, char* output_string)
{
  /* Some helpful variables you might want to use */
  int* scores = NULL;
  int sample_length = strlen(sample_segment);
  int candidate_length = 0;
  int i = 0;
  int has_perfect_match = 0;
  int score = 0;
  char outputline_buffer[BUFSIZE] = "\0";
  char int_buffer[BUFSIZE];

  /* Hint: Check to see if any candidate segment(s) are a perfect match, and report them
     (REMEMBER: don't ignore trailing nucleotides when searching for a perfect score)
     Report the result by concatenating to output_string using the strcat(...) function.
     See the comments above this function for the output string format for each line
     Use sprintf(char * str, const char * format, ...) to convert an integer into string
     which can then be concatenated using strcat(...) 
     e.g. sprintf(int_buffer, "%d", i);
          strcat(outputline_buffer, "Candidate number ");
          strcat(outputline_buffer, int_buffer);
          strcat(outputline_buffer, " is a perfect match\n");*/

  // Insert your code here

  for (i = 0; i < number_of_candidates; i++) {
      has_perfect_match = 1;
      candidate_length = strlen(*(candidate_segments + i));
      for (int j = 0; j < candidate_length; j++) {
          if (sample_segment[j] != *(*(candidate_segments + i) + j)) {
              has_perfect_match = 0;
              break;
          }
      }
      if (has_perfect_match) {
          sprintf(int_buffer, "%d", (i+1));
          strcat(outputline_buffer, "Candidate number ");
          strcat(outputline_buffer, int_buffer);
          strcat(outputline_buffer, " is a perfect match\n");
          strcat(output_string, outputline_buffer);
      }
  }

  /* Hint: Return early if we have found and reported perfect match(es) */

  // Insert your code here

  if (has_perfect_match) {
      return;
  }

  /* Hint: Otherwise we need to calculate and print all of the scores by invoking
     calculate_score for each candidate_segment. Write an output line for each
     candidate_segment and concatenate your line to output_string.
     Don't forget to clear your outputline_buffer for each new line*/
  for (i = 0; i < number_of_candidates; ++i) {

    // Insert your code here - maybe a call to calculate_score?
      score = calculate_score(sample_segment, *candidate_segments);
      sprintf(int_buffer, "%d", (i + 1));
      strcat(outputline_buffer, "Candidate number ");
      strcat(outputline_buffer, int_buffer);
      strcat(outputline_buffer, " matches with a score of ");
      sprintf(int_buffer, "%d", score);
      strcat(outputline_buffer, int_buffer);
      strcat(outputline_buffer, "\n");
      strcat(output_string, outputline_buffer);
  }

  /* End of function */
  return;
}

/*
 * Compares the sample segment and the candidate segment and calculates a
 * score based on these rules:
 *
 * 1. The score begins at 0.
 * 2. Let LENGTH be the number of codons in sample segment (which is always <= the candidate's length)
 * 3. Ignore any trailing nucleotides (there may be 1 or 2, but not more)
 * 4. For each of the LENGTH codons:
 *    a) if the two codons are exactly the same, add 10 to the score
 *    b) else if the 2 codons are different but specify the same amino acid, add 5 to the score
 *    c) else if the two codons are different and do not specify the same amino acid, then
 *       examine the 3 nucleotides in the codon separately:
 *		 For each of the 3 nucleotides:
 *		i)   If the two nucleotides are the same, add 2 to the score
 *      ii)  If the 2 nucleotides belong to a matching base pair (A and T, or C and G), add 1
 *      iii) Otherwise, add zero to the score (e.g., do nothing)
 * 5. Store the result
 * 6. Now skip the first codon in the candidate, e.g., shift the sample by 1 codon,
 *    and check the score of this new alignment.  Compare this score to the score
 *    you calculated before shifting, and store the higher score.  Keep shifting
 *    the sample deeper into the candidate by one codon at a time, checking the score, and
 *    storing ONLY the top score, until itno longer fits. Once the sample (ignoring the
 *    trailing nucleotides) extends beyond the length of the candidate we stop.
 * PARAM:     pointer to the sample segment
 * PARAM:     pointer to the candidate segment
 * PRE:       pointers are valid pointers to dynamically allocated and populated memory
 * POST:      NULL
 * RETURN:    An int score representing to degree to which the two segments match.
 */
int calculate_score(char* sample_segment, char* candidate_segment)
{
  /* Some helpful variables you might (or might not) want to use */
  int temp_score = 0;
  int score = 0;
  int iterations = 0;
  int sample_length = strlen(sample_segment);
  int candidate_length = strlen(candidate_segment);
  int sample_length_in_codons = sample_length / 3; // number of condons in sample length

  char codon_sample[4] = "";
  char codon_candidate[4] = "";
   
  // Insert your code here (replace this return statement with your own code)
  for (int k = 0; k <= (candidate_length - sample_length); k=k+3) {
    score = 0;
    iterations = (sample_length - (sample_length % 3));
    if (&candidate_segment[k + 3] == NULL) break;
    for (int i = 0; i < sample_length; i = i + 3) {
      
      strncpy(codon_sample, &sample_segment[i], 3 * sizeof(char));
      strncpy(codon_candidate, &candidate_segment[i + k], 3 * sizeof(char));
      

      if (strcmp(codon_sample, codon_candidate) == 0) {
        score += 10;
      }
      else if (strcmp(codon_names[get_codon_index(codon_candidate)], codon_names[get_codon_index(codon_sample)]) == 0) {
        score += 5;
      }
        else {
          for (int n = 0; n < 3; n++) {
            // check if the codons have matching names    
            if (strncmp(&codon_sample[n], &codon_candidate[n], sizeof(char)) == 0) {
              score += 2;
            }
            // check if the codons have matching base pairs
            if (is_base_pair(codon_sample[n], codon_candidate[n])) {
              score += 1;
            }
          }
        }
    }
    if (score > temp_score) {
        temp_score = score;
    }
  }
  

  return temp_score;
}