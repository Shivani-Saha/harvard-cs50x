#include<math.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#include "forest.h"
#include "huffile.h"
#include "tree.h"

int main(int argc, char* argv[])
{
    if(argc!=3)
    {
        printf("Usage: %s input output\n", argv[0]);
        return 1;
    }
    Huffile* input = hfopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s for reading.\n", argv[1]);
        return 1;
    }

    // read in header
    Huffeader header;
    if (hread(&header, input) == false)
    {
        hfclose(input);
        printf("Could not read header.\n");
        return 1;
    }

    // check for magic number
    if (header.magic != MAGIC)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }

    // check checksum
    int checksum = header.checksum;
    for (int i = 0; i < SYMBOLS; i++)
    {
        checksum -= header.frequencies[i];
    }
    if (checksum != 0)
    {
        hfclose(input);
        printf("File was not huffed.\n");
        return 1;
    }
    
    //Forest contruction
    Forest* f = mkforest();
    if(f==NULL)
    {
        printf("Forest not allocated.");
        return 1;
    }
    
    for(int index=0; index<127; index++)
    {
            Tree* t = mktree();
            if(t==NULL)
            {
                printf("Tree not allocated.");
                return 1;
            }
            t->symbol = (char)index;
            t->frequency = header.frequencies[index];
            if(!plant(f,t))
                rmtree(t);
    }
        
    //Huffman tree construction
    Tree* t1 = pick(f);
    if(t1==NULL)
    {
        printf("Empty forest");
        return 1;
    }
    Tree* t2=NULL;
    while( (t2=pick(f))!=NULL )
    {
        int freq = (t1->frequency + t2->frequency);
        Tree* temp = mktree();
        temp->frequency=freq;
        temp->left=t1;
        temp->right=t2;
        t1=temp;
    } 
    Tree* root=t1;
    
    //Decompression
    int bit;
    FILE* output=fopen(argv[2],"w");
    if(output==NULL)
    {
        printf("%s cannot open!",argv[2]);
        exit(1);
    }
    Tree* temp=root;
    while ((bit = bread(input)) != EOF)
    {
            if(bit==0)
            {
                temp=temp->left;              
            }
            else
            {
                temp=temp->right;              
            }          
            if((temp->left==NULL)&&(temp->right==NULL))
            {
                fwrite(&(temp->symbol),1,1,output);  
                temp=root;      
            }
    }
    
    //Free nodes
    hfclose(input);
    fclose(output);
    rmtree(root);
    rmforest(f);
    return 0;   
}
