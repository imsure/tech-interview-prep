/*
 * Implement the unix "tail" command that can look up the last 10 lines
 * of a file efficiently.
 */

#include "common.hpp"

// seek to the end of the file stream and then
// read backwards byte by byte (too many IOs!), couting the number of '\n' to
// determine when to stop.

void mytail1(string fname, int n)
{
  ifstream myfile (fname, ios::in);
  if (myfile.is_open()) {
    int pos = 0;

    char c;
    stringstream ss;
    int line_counter = 0;

    while (true) {
      myfile.seekg(--pos, ios::end);
      if (myfile.tellg() >= 0) {
        myfile.get(c);
        if (c == '\n') ++line_counter;
        if (line_counter > n) break;
        ss << c;
      } else {
        break;
      }
    }

    string s = ss.str();
    std::reverse(s.begin(), s.end());
    cout << s;

    myfile.close();
  } else {
    cout << "Unable to open the file " << fname << endl;
  }
}

// read in a block (1024bytes) at one time then counts the number of
// newlines

void mytail2(string fname, int n)
{
  const int blocksize = 1024;

  ifstream myfile (fname, ios::in);
  if (myfile.is_open()) {
    myfile.seekg(0, ios::end);
    int filesize = myfile.tellg();
    myfile.seekg(0, ios::beg);

    vector<string> nlines;
    char buf[blocksize];
    int block_read = 0;
    int line_counter = 0;

    while (true) {
      int bytes_read;
      bool file_exhausted;

      if (filesize - block_read * blocksize >= blocksize) {
        myfile.seekg(filesize - (++block_read * blocksize), ios::beg);
        myfile.read(buf, blocksize); // read the block
        bytes_read = blocksize;
        file_exhausted = false;
      } else {
        myfile.seekg(0, ios::beg);
        myfile.read(buf, filesize - block_read * blocksize);
        bytes_read = filesize - block_read * blocksize;
        file_exhausted = true;
      }

      bool keepgoing = true;
      for (int i = bytes_read - 1; i >= 0; --i) {
        if (buf[i] == '\n') {
          if (++line_counter > n) {
            nlines.push_back(string(buf+i+1, bytes_read - i - 1));
            keepgoing = false;
            break;
          }
        }
      }

      if (keepgoing) nlines.push_back(string(buf, bytes_read));
      else break;

      if (file_exhausted) break;
    }

    for (int i = nlines.size() - 1; i >= 0; --i)
      cout << nlines[i];

    myfile.close();
  } else {
    cout << "Unable to open the file " << fname << endl;
  }
}

int main(int argc, char** argv)
{
  if (argc > 1) mytail2(string (argv[1]), 10);
  else cout << "Please provide with a file name!\n";
}
