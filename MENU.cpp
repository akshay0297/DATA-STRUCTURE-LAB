#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>


void main ()
{
clrscr();
    int i , j , k , p , l=0 ;
    char s1[100] , s2[100];
    cout<<"For string length press 1 !"<<endl;
    cout<<"For string concatenation press 2 !"<<endl;
    cout<<"For string comparison press 3 !"<<endl;
    cout<<"To insert a sub string press 4 !"<<endl;
    cout<<"To delete a substring press 5 !"<<endl;
    cout<<"Enter your choice : ";
    cin>>p;

    switch(p)
     {

    case 1 :   cout<<"Enter the string to calculate its length : "<<endl;
	       cin.getline(s1,100);
	       cin.getline(s1,100);
	       for(i=0 ; s1[i]!='\0';i++)
		  l++;
	       cout<<"The length of string you entered is : "<<l <<endl;
	       break;
    case 2 :   cout<<"Enter two strings to concatenate : "<<endl;
	       cout<<"Enter first string : ";
	       cin.getline(s1,100);
	       cin.getline(s1,100);
		cout<<"Enter second string : ";
		cin.getline(s2,100);
	       for(i=0; s1[i]!='\0'; ++i);
	       for(j=0; s2[j]!='\0'; ++j, ++i)
		{
		    s1[i]=s2[j];
		}
	      s1[i]='\0';
	      cout << "After concatenation: " << s1;
	      break;
      case 3 : cout<<"Enter two strings to compare : "<<endl;
	       cout<<"Enter first string : ";
	       cin.getline(s1 , 100);
	       cin.getline(s1 , 100);
	       cout <<"Enter second String : ";
	       cin.getline(s2 , 100);
		i = 0;
		while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
		if (s1[i] > s2[i])
		    cout<<"String 1 greater than string 2 !"<<endl;
		else
		    if (s1[i] < s2[i])
			cout<<"String 2 greater than string 1 !"<<endl;
		    else
			cout<<"Both strings are same !"<<endl;
		break;

       case 4 :
		       {
			    char a[10];
			    char b[10];
			    char c[10];
			    int p=0,r=0,i=0;
			    int t=0;
			    int x,g,s,n,o;

			    puts("Enter First String:");
			    gets(a);
			    gets(a);
			    puts("Enter Second String:");
			    gets(b);
			    printf("Enter the position where the item has to be inserted: ");
			    cin>>p;
			    r = strlen(a);
			    n = strlen(b);
			    i=0;

			    while(i <= r)
			    {
				c[i]=a[i];
				i++;
			    }
			    s = n+r;
			    o = p+n;

			    for(i=p;i<s;i++)
			    {
				x = c[i];
				if(t<n)
				{
				    a[i] = b[t];
				    t=t+1;
				}
				a[o]=x;
				o=o+1;
			    }
			    puts(a);
			    break;
     }

       case 5:
		    int len1,len2,i,cntr1,cntr2,flag=0;
		    char str1[50],str2[50];
		    cout<<"Enter the main String : \n";
		    gets(str1);
		 //   gets(str1);
		    cout<<"Enter subString : ";
		    gets(str2);
		    len1=strlen(str1);
		    len2=strlen(str2);
		    for(i=0;len2<=len1-i;i++)
		{
		    for(cntr1=i,cntr2=0;cntr2<=len2&&str1[cntr1]==str2[cntr2];cntr1++,cntr2++);
		    if(len2<=cntr2)
			{
			    flag=1;
			    break;
			}
		}
		    if(flag==0)
		   {

		    puts(str2);
		    cout<<"Is not present in ";
		    puts(str1);
		    cout<<"so it cannot be deleted";
		   }
		else
		    {
		    for(;(i+len2+1)<=len1;i++)
		    str1[i]=str1[len2+i];
		    str1[i]='\0';

		cout<<"The string after deleting is : ";
		puts(str1);
		    }
		break;

	}
	getch();
}