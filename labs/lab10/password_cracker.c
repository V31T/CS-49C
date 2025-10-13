#include <stdio.h>
#include <stdlib.h>

#include "sha256.h"
#include "hash_table.h"

// Digest size is 256 bits, or 32 bytes.
// Using 64 characters for hex value, plus 1 for null terminator.
#define DIGEST_SIZE 65

#define BUFF_SIZE 256

void hash_password(char* pwd_in, char* digest_out) {
    sha256_easy_hash_hex(pwd_in, strlen(pwd_in), digest_out);
}

HashTable* build_password_hash(char* file_name) {
    HashTable* ht = ht_create();

    FILE* f;
    char password[BUFF_SIZE];
    char hash_digest[DIGEST_SIZE];

    f = fopen(file_name, "r");

    if (f == NULL) {
        perror("Error opening common password file\n");
        exit(1);
    }

    //
    // **YOUR CODE HERE**
    //
    // Read over the password file line-by-line.
    // (Optional) skip any line that begins with a '#'.
    // Remove the newline if there is one, hash the password,
    // and store the result in the ht hash table.
    // The key should be the hash and the value should be
    // the actual password.
    //

    fclose(f);

    return ht;
}

void break_passwords(HashTable* common_passwords, char* file_name) {
    FILE* f;
    char line[BUFF_SIZE];

    const char* delim = " \n\t";

    f = fopen(file_name, "r");

    if (f == NULL) {
        perror("Error opening login credentials file\n");
        exit(1);
    }

    //
    // **YOUR CODE HERE**
    //
    // Using a string tokenizer, get the username and the password hash.
    // Look up the hash value in the common_ passwords hash table.
    // Print out the username/password if you break the password,
    // or note that you could not break the password otherwise.
    //

    fclose(f);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <password_file> <login_credentials_file>\n", argv[0]);
        exit(1);
    }

    char* common_password_file = argv[1];
    char* login_credentials_file = argv[2];

    HashTable* common_passwords = build_password_hash(common_password_file);

    break_passwords(common_passwords, login_credentials_file);
}
