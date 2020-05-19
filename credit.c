#include <stdio.h>
#include <cs50.h>

int main(void)
{
  long user_card = get_long("Card number: ");
  long card_number = user_card;
  long card_digits = card_number / 10;
  long digit_to_sum;
  long checksum = 0;
  long counter = 0;

  while (card_number != 0)
  {
    digit_to_sum = (card_digits % 10) * 2;
    if (digit_to_sum >= 10)
    {
      digit_to_sum = (digit_to_sum % 10) + 1;
    }
    card_number = card_digits / 100;
    checksum += digit_to_sum;
    card_digits = card_number;
    counter++;
  }

  card_number = user_card;
  long card_brand = card_number;
  int isVISA = card_brand / 1000000000000;
  int isAMEX = card_brand / 10000000000000;
  int isMASTERCARD = card_brand / 100000000000000;

  while (card_number != 0)
  {
    digit_to_sum = card_number % 10;
    checksum += digit_to_sum;
    card_digits = card_number;
    card_number = card_digits / 100;
    counter++;
  }

  // If you would like to know the card lenght
  // printf("counter is on: %i\n", counter);

  // If you would like to know the final checksum
  // printf("final cheksum result: %ld\n", checksum);

  if (counter < 13) {
    printf("Card number is too short!\n");
  }

  int validation_test = checksum % 10;

  // AMERICAN EXPRESS
  if (validation_test == 0 && counter == 15 && (isAMEX == 34 || isAMEX == 37))
  {
    printf("AMEX\n");
  } 
  
  // MASTERCARD OR VISA
  else if (
    validation_test == 0 && 
    counter == 16 &&
    (isMASTERCARD >= 51 && isMASTERCARD <= 55)
    )
  {
    printf("MASTERCARD\n");
  } 
  else if (
    validation_test == 0 && 
    counter == 16 &&
    (isMASTERCARD / 10) == 4)
  {
    printf("VISA\n");
  }

  // VISA
  else if (validation_test == 0 && counter == 13 && isVISA == 4)
  {
    printf("VISA\n");
  }

  else
  {
    printf("INVALID CREDIT/DEBIT CARD\n");    
  }
}