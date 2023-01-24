#!/usr/bin/perl
# Tcp line echo Server  (non-concurrent)
# terminates client session when <> returns undef 
# terminates server after 5 connections
# Peter Walsh csci 251

use IO::Socket;
$sock = new IO::Socket::INET (
                              LocalHost => '',
                              LocalPort => '7075',
                              Proto => 'tcp',
                              Reuse => 1,
                              Listen => 2
                              );
die "Could not create socket: $!\n" unless $sock;

$num=0;
while ($new_sock = $sock->accept()) {
   print "Client count ", $num , " established\n";
   while (defined ($line=<$new_sock>)) {
      print $line;
   }
   close($new_sock);
   print "Client count ", $num , " terminated\n";
   $num++;
   last if ($num==5);
}

close($sock);

