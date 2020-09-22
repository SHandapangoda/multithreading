#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
using namespace std;

#define NUM_THREADS 5
void sleep(float time){
    time=time*1000;

time_t start=clock();
time_t finish=clock();
float difference=finish-start;
}

void timez(){


cout <<"LOCAL TIME"<<endl;

}
void *wait(void *t){


long tid;

tid=(long)t;
    sleep(1);
    cout << "Sleeping thread" << endl;
    cout << "Thread with id: " << tid << endl;
pthread_exit(NULL);

return 0;
}
int main()
{
    int rc;
    int i;
      pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   void *status;

      pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(i=0;i<NUM_THREADS;i++){
        cout << "Creating thread @main()" << i << endl;
        rc=pthread_create(&threads[i], &attr, wait, (void *)i);

        if(rc){
            cout << "Unable to create thread " << rc << endl;
            exit(-1);
        }
    }
pthread_attr_destroy(&attr);
for( i = 0; i < NUM_THREADS; i++ ) {
      rc = pthread_join(threads[i], &status);
      if (rc) {
         cout << "Error:unable to join," << rc << endl;
         exit(-1);
      }
      cout << "Main: completed thread id :" << i ;
      cout << "  exiting with status :" << status << endl;
   }

   cout << "Main: program exiting." << endl;
   pthread_exit(NULL);

}
