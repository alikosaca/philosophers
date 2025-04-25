/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:07:37 by akosaca           #+#    #+#             */
/*   Updated: 2025/04/18 17:10:00 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

// Mutex tanımlama - paylaşılan kaynaklar için
pthread_mutex_t paket_mutex;

// Koşul değişkeni - thread'ler arası senkronizasyon için
pthread_cond_t paket_hazirlandi;

// Paylaşılan değişken
int teslim_edilen_paket_sayisi = 0;

void *deliver_package(void *arg)
{
    int worker_id;

    worker_id = *(int *)arg;
    
    // Thread kendi ID'sini göstersin
    pthread_t thread_id = pthread_self();
    printf("Çalışan #%d (Thread ID: %lu): Paketi teslim etmeye gidiyorum...\n", worker_id, thread_id);

    usleep(5000000);

    // Paylaşılan veriyi güncelleme - mutex ile koruyoruz
    pthread_mutex_lock(&paket_mutex);
    teslim_edilen_paket_sayisi++;
    printf("Çalışan #%d: Paket teslim edildi! Toplam: %d\n", worker_id, teslim_edilen_paket_sayisi);

    // Eğer tüm paketler teslim edildiyse, koşul değişkeni ile bildirelim
    if (teslim_edilen_paket_sayisi == 5) {
        pthread_cond_signal(&paket_hazirlandi);
    }
    
    pthread_mutex_unlock(&paket_mutex);
    
    // Thread'in kendini sonlandırması
    // pthread_exit(NULL); // Normalde buna gerek yok, fonksiyon bitince thread sonlanır
    return NULL;
}

int main(void)
{
	pthread_t workers[5];
	int ids[5];
    int i;

	// Mutex ve koşul değişkenini başlat
	pthread_mutex_init(&paket_mutex, NULL);
	pthread_cond_init(&paket_hazirlandi, NULL);

    printf("CEO: Herkes görevini alsın ve teslimata başlasın!\n");
    i = 0;
    while (i < 5)
    {
        ids[i] = i + 1;
        pthread_create(&workers[i], NULL, deliver_package, &ids[i]);
        
        // İstersek thread'i bağımsız yapabiliriz (join gerekmez)
        // pthread_detach(workers[i]);
        
        i++;
    }
    
	// Mutex ile korunan bir bekleme döngüsü
	pthread_mutex_lock(&paket_mutex);
	while (teslim_edilen_paket_sayisi < 5) {
		// Tüm paketler teslim edilene kadar bekle
		pthread_cond_wait(&paket_hazirlandi, &paket_mutex);
	}
	pthread_mutex_unlock(&paket_mutex);

	// Eğer thread'leri detach etmediysek
    i = 0;
    while (i < 5)
    {
        pthread_join(workers[i], NULL);
        i++;
    }
    
    printf("CEO: Tüm paketler teslim edildi, bravo ekibim!\n");

    // Mutex ve koşul değişkenini temizle
    pthread_mutex_destroy(&paket_mutex);
    pthread_cond_destroy(&paket_hazirlandi);
    
    return (0);
}
