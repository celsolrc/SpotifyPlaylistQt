# PlaylistQT  for Spotify

PlaylistQT é um demo para criação de uma playlist com armazenamento local para o Spotify. Tem como finalidade principal somente demonstrar os recursos do Qt e como meta, acessar o Spotify.

Nesta primera etapa o acesso ao Spotify não está completo e ainda existem alguns detalhes a serem melhorados

# Problemas identificados

  - Falha de segurança: a senha de acesso ao Spotify está sendo armazenada localmente e sem criptografia.
  - Não é apresentada nenhuma mensagem indicativa em caso de falha na gravação ou leitura de qualquer arquivo (de configuração ou playlists)


# Implementações futuras
- Não está acessando a API do Spotify. Com isso, as "musicas" listadas são textos fixos dentro do código
- Pelo mesmo motivo acima, não executa nenhuma música

# Melhorias futuras
- Uso de SIGNAL e SLOTS para melhor independencia e segurança no código
