int main()
{
  int j;
  char* invite = "Mots : ";
  printf("%s",invite);
  printf("\n");

  while((j = yylex()))
    printf("\nRésultat : Jeton = %d ; Lexeme = %s\n%s", j, invite);

  return 0;
}
