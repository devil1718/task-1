#include <stdio.h>
#include <string.h>

#define size 100

struct User
{
  char username[30];
  char password[30];
};

int main()
{

  int num;
  int userNum = 0;
  struct User users[size];

  while (1)
  {

  char username[30];
  char password[30];

    printf("To register enter 1\nTo login enter 2\nTo Exit enter 3\nEnter a number: ");
    scanf("%d", &num);

    if (num == 1)
    {

      if (userNum >= size)
      {
        printf("The users is full\n");
        continue;
      }

      printf("Enter your username: ");
      scanf("%s", &username);
      int flag = 0;
      for (int i = 0; i < userNum; i++)
      {
        if (strcmp(username, users[i].username) == 0)
        {
          printf("Username already exists\n");
          flag = 1;
          break;
        }
      }
      if (flag) {
        continue;
      }
      printf("Enter your password: ");
      scanf("%s", &password);

      struct User user;
      strcpy(user.username, username);
      strcpy(user.password, password);
      users[userNum] = user;
      userNum++;
      printf("Registered\n");
    }
    else if (num == 2)
    {

      printf("Enter your username: ");
      scanf("%s", &username);
      printf("Enter your password: ");
      scanf("%s", &password);

      int flag = 0;
      for (int i = 0; i < userNum; i++)
      {

        if ((strcmp(username, users[i].username) == 0) && (strcmp(password, users[i].password) == 0))
        {
          printf("You are logged in\n");
          flag = 1;
          continue;
        }
      }
      if (flag) {
        continue;
      }
      printf("Invalid username or password\n");
    }
    else if (num == 3)
    {
      break;
    }
    else
    {
      printf("Invalid number\n");
    }
  }
}
