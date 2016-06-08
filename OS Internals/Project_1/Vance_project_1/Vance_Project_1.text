/* 
* Alex Vance
* CEG 4350 Summer 2016
* Project 1: Producer / Consumer Problem
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

//initial global declarations if user doesn't specify
int BUFFER_SIZE = 10;
int THREAD_COUNT = 6;
int NUM_PRODUCERS = 2;
int NUM_CONSUMERS = 2;
int MAX_ITEMS = 20;

//pointer to buffer array
int * buffer;
//index for buffer array
int buffer_index;
//mutex lock for thread control
pthread_mutex_t buffer_mutex;
//semaphores
sem_t full_semaphore;
sem_t empty_semaphore;

/*
* Adds to buffer array of values 
* @param int The number to insert into the buffer
*/
void buffer_insert(int num){
  //entry section
  if(buffer_index < BUFFER_SIZE) {
    //critical section
    buffer[buffer_index++] = num;
    //exit section
  }
  //remainder section
}

/*
* Remove from the buffer array of values 
*/
int buffer_remove(){
  //entry section
  if(buffer_index > 0){
    //critical section
    return buffer[--buffer_index];
    //exit section
  }
  return 0;
  //remainder section
}

/*
* Create producer on thread to produce item for buffer
@param void thread that producer can exist on
*/
void *producer(void *thread) {
  int number;
  int count = 0;
  int thread_id = *(int *)thread;
  
  while(count++ < NUM_PRODUCERS){
    //sleep (aesthetic to show to screen)
    //entry section
    sleep(rand() % 10);
    number = rand() % 100;
    //critical section
    sem_wait(&full_semaphore);
    //lock mutex, perform operation, unlock
    pthread_mutex_lock(&buffer_mutex);
    buffer_insert(number);
    pthread_mutex_unlock(&buffer_mutex);
    //alarm other semaphore
    sem_post(&empty_semaphore);
    //exit section
    printf("Producer %d produced item %d on buffer %d", thread_id, number, count);
  }
  pthread_exit(0);
  //remainder section
}

/*
* Create consumer on thread to consume item from buffer
@param void thread that consumer can exist on
*/
void *consumer(void *thread){
  //entry section
  int number;
  int count = 0;
  int thread_id = *(int *)thread;

  while(count++ < NUM_CONSUMERS){
    //critical section
    sem_wait(&empty_semaphore);
    //lock mutex, perform operation, unlock
    pthread_mutex_lock(&buffer_mutex);
    number = buffer_remove(number);
    pthread_mutex_unlock(&buffer_mutex);
    //alarm other semaphore
    sem_post(&full_semaphore);
    printf("Consumer %d consumed item %d on buffer %d", thread_id, number, count);
    //exit section
  }
  pthread_exit(0);
  //remainder section
}

/*
* Main method
@param int argc The count of arguments passed in
@param char[] array of parameters passed in
*/
int main(int argc, char *argv[]) {

  //if there were arguements passed in, use those values
  if(argc >1){
    BUFFER_SIZE = (int) argv[1];
    NUM_PRODUCERS = (int) argv[2];
    NUM_CONSUMERS = (int) argv[3];
    MAX_ITEMS = (int) argv[4];
  }

  //create buffer sized array, set buffer * 
  int array[BUFFER_SIZE];
  buffer = array;

  //create objects, mutex, semaphores and threads
  buffer_index = 0;
  pthread_mutex_init(&buffer_mutex, NULL);
  sem_init(&full_semaphore,0,BUFFER_SIZE);
  sem_init(&empty_semaphore,0,0);
  pthread_t thread[THREAD_COUNT];
  int thread_id[THREAD_COUNT];

  //create threads, producers one ahead of consumers
  for( int i = 0; i < THREAD_COUNT; i++){
    thread[i] = i;
    pthread_create(thread + i, NULL, producer, thread_id + i);
    thread_id[i] = i;
    pthread_create(&thread[i], NULL, consumer, &thread_id[i]);
  }

  //join the threads to end them
  for(int j = 0; j < THREAD_COUNT; j++){
    pthread_join(thread[j], NULL);
  }

    //destroy the buffer mutex, semaphores and return
    pthread_mutex_destroy(&buffer_mutex);
    sem_destroy(&full_semaphore);
    sem_destroy(&empty_semaphore);

    return 0;
}