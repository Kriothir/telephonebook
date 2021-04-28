# telephonebook

Simple Telephone Book Data Structure

Add a new entry:
./demo_baza -o 4 4<>xpo.dat -tel 022207000 -ime Janez -priimek Novak -dan 23 -mesec 1 -leto 1985

Search for an entry:
./demo_baza -o 3 3<>xpo.dat -ime Janez -priimek Novak
#Note: You can either search with ime, priimek or both

Delete an entry with specified id:
 ./demo_baza -o 9 9<>xpo.dat -id 1
 
 Create a binary file that stores the names and numbers:
 ./demo_baza -c
