CurrencyC.java
package cc;
import java.util.*;
public class CurrencyC
{
double inr,usd;
double euro,yen;
Scanner in=new Scanner(System.in);
public void dollartorupee()
{
System.out.println("Enter dollars to convert into Rupees:");
usd=in.nextInt();
inr=usd*81.83;
System.out.println("Dollar ="+usd+" equal to INR="+inr);
System.out.println("\n");
}
public void rupeetodollar()
{
System.out.println("Enter Rupee to convert into Dollars:");
inr=in.nextInt();
usd=inr/81.83;
System.out.println("Rupee ="+inr+"equal to Dollars="+usd);
}
public void eurotorupee()
{
System.out.println("Enter Euro to convert into Rupees:");
euro=in.nextInt();
inr=euro*79.06;
System.out.println("Euro ="+euro+" equal to INR="+inr);
System.out.println("\n");
}
public void rupeetoeuro()
{
System.out.println("Enter Rupees to convert into Euro:");
inr=in.nextInt();
euro=(inr/79.06);
System.out.println("Rupee ="+inr +"equal to Euro="+euro);
System.out.println("\n");
}
public void yentoruppe()
{
System.out.println("Enter Yen to convert into Rupees:");
yen=in.nextInt();
inr=yen*0.57;
System.out.println("Yen ="+yen+" equal to INR="+inr);
System.out.println("\n");
}
public void ruppetoyen()
{
System.out.println("Enter Rupees to convert into Yen:");
inr=in.nextInt();
yen=(inr/0.57);
System.out.println("INR="+inr +"equal to YEN"+yen);
System.out.println("\n");
}
}
DistaceC.Java
package dc;
import java.util.*;
public class DistanceC
{
double km,m,miles;
Scanner in=new Scanner(System.in);
public void mtokm()
{
System.out.println("Enter the distance in meter");
m=in.nextDouble();
km=(m/1000);
System.out.println(m+"m" +" is equal to "+km+"km");
System.out.println("\n");
}
public void kmtom()
{
System.out.println("Enter the distance in Kilometer");
km=in.nextDouble();
m=km*1000;
System.out.println(km+"km" +" is equal to "+m+"m");
System.out.println("\n");
}
public void milestokm()
{
System.out.println("Enter the distance in miles");
miles=in.nextDouble();
km=(miles*1.60934);
System.out.println(miles+"miles" +" is equal to "+km+"km");
System.out.println("\n");
}

public void kmtomiles()
{
System.out.println("Enter the distance in km");
km=in.nextDouble();
miles=(km*0.621371);
System.out.println(km+"km" +" is equal to "+miles+"miles");
}
}
TimeC.java
package tc;
import java.util.*;
public class TimeC
{
int hours,seconds,minutes;
Scanner in = new Scanner(System.in);
public void hourstominutes()
{
System.out.println("Enter the no of Hours to convert into minutes");
hours=in.nextInt();
minutes=(hours*60);
System.out.println("Minutes: " + minutes);
}
public void minutestohours()
{
System.out.println("Enter the no of Minutes to convert into Hours");
minutes=in.nextInt();
hours=minutes/60;
System.out.println("Hours: " + hours);
}
public void hourstoseconds()
{
System.out.println("Enter the no of Hours to convert into Seconds");
hours=in.nextInt();
seconds=(hours*3600);
System.out.println("Seconds: " + seconds);
}
public void secondstohours()
{
System.out.println("Enter the no of Seconds to convert into Hours");
seconds=in.nextInt();
hours=seconds/3600;
System.out.println(seconds+"seconds"+ " is equal to "+hours+"hour");
}
}
Main Class
import cc.*;
import dc.*;

import tc.*;
public class Main
{
public static void main(String args[])
{
CurrencyC obj=new CurrencyC();
DistanceC obj1=new DistanceC();
TimeC obj2=new TimeC();
obj.dollartorupee();
obj.rupeetodollar();
obj.eurotorupee();
obj.rupeetoeuro();
obj.yentoruppe();
obj.ruppetoyen();
obj1.mtokm();
obj1.kmtom();
obj1.milestokm();
obj1.kmtomiles();
obj2.hourstominutes();
obj2.minutestohours();
obj2.hourstoseconds();
obj2.secondstohours();
}
}
