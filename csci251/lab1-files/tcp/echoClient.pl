#!/usr/bin/perl
# Tcp line echo client
# terminates when "CLOSE\n" is sent
# Peter Walsh csci 251

use IO::Socket;
$sock = new IO::Socket::INET (
                              PeerAddr => 'otter.viu.ca',
                              PeerPort => '7075',
                              Proto => 'tcp',
			      Reuse => 1
                             );
die "Could not create socket: $!\n" unless $sock;

print "Enter text to be sent to server followed by crlf\n";
print "Enter CLOSE followed by crlf to close the connection\n";

$line=<>;
while ($line ne "CLOSE\n") {
   print $sock $line;
   $line=<>;
}

close($sock);


