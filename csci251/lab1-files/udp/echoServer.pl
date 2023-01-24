#!/usr/bin/perl
# Udp line echo server
# Peter Walsh csci 251

use IO::Socket;

$sock = new IO::Socket::INET (
                              LocalHost => '',
                              LocalPort => '7072',
                              Proto => 'udp',
                              Reuse => 1
                              );
die "Could not create socket: $!\n" unless $sock;

$num=0;
while (1) {
   $sock->recv($buff,128);
   print "$buff";
   $num++;
   last if ($num==3);
}

close($sock);
