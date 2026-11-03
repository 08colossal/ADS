##### **Questionário Banco de Dados**





###### **3. DB-Engines e Rankings**

3.1) O que é DB-Engines e qual é seu propósito?

\-"É uma iniciativa de coletar e apresentar informações sobre Sistemas de Gerenciamento de Banco de Dados (SGBD), assuntos de NOSQL são destacados."

\-Uma db-engine é responsável por fornecer as funcionalidades principais de um banco de dados: armazenar, processar e recuperar dados. Permite que os usuários interajam com os dados de forma eficiente e segura.



3.2) Cite os 5 parâmetros que DB-Engines usa para calcular o ranking de SGBDs:

* Número de menções sobre o sistema em websites;
* Interesse geral no sistemas (google trends);
* Frequência de discussões técnicas sobre o sistema;
* Número de ofertas, nas quais o sistema é mencionado;
* Número de perfis em sites de networking, nos quais o sistema é mencionado, como o LinkedIn;
* Relevância do assunto em redes sociais, como twitter.



3.3) Qual é o Top 3 de bancos de dados no DB-Engines em 2026? Por que eles ocupam essas posições?

1. Oracle

2. MySQL

3. Microsoft SQL Server

-Ambas são bancos relacionais; em geral, utilizando os parâmetros de classificação.

&#x20;



3.4 - Site: www.db-engines.com oferece quais recursos úteis?

-Você pode analisar os bancos de dados e sua classificação, para gerenciar sua escolha, porém a classificação se baseia em quais são mais citados. Pode também examinar as propriedades de cada um e compará-los.



&#x20;



###### **4. Análise do Banco de Dados Escolhido**

-Escolha um dos bancos de dados mencionados no DB-Engines (Oracle, MySQL, PostgreSQL, SQL Server, MongoDB, Redis, Snowflake, Elasticsearch ou SQLite) e responda às questões abaixo:



&#x20;



4.1 - Nome do banco de dados escolhido:

-PostgreSQL.

&#x20;



4.2) Posição no ranking DB-Engines:

-4º lugar.





4.3) Classifique o banco (Relacional / NoSQL / Search Engine / Cloud / Outro):

-Relacional, graph, spatial e vector SGBD.

&#x20;



4.4) Características principais deste banco de dados:

-Implementado em C, SO's: FreeBSD, HP-UX, LINUX, NETBSD, OPENBSD, OS X, Solaris, UNIx e WINDOWS. APIS de acesso: ADO.NET, JDBC, biblioteca nativa de C, ODBC.

-Tem suporte para: .Net, C, C++, Delphi, Java, JS, Perl, PHP, Python, Tcl.

-Particionamento: tamanho, listas e hash.



4.5) Cite 3 casos de uso práticos onde este banco seria ideal:

1. "Gatilho de inserção básico" - para registrar cada operação de entrada em uma tabela

2. "Atualizar gatilho com condição" - para atualizar campos em uma tabela sempre que uma linha for modificada 

3. "Adicionador de complexo para auditoria" - para registrar alterações feitas em uma tabela utilizando dados antigos

&#x20;



4.6) Qual é o modelo de licença? (Comercial / Open-source / SaaS / Hybrid)

Open-source

&#x20;



4.7) Cite 3 vantagens e 3 desvantagens deste banco de dados:

-Vantagens:
1. Suporta consultas complexas, dados customizados e JSON
2. Alta segurança de dados, ACID
3. Não possui licensa paga, é open-source
-Desvantagens:
1. Pode exigir mais capacidade de processamento que outras opções
2. Configurações complicadas para iniciantes 
3. Para leituras simples outros db apresentam melhor desempenho (nativo)


&#x20;



\- Qual é a tendência deste banco no mercado? Está crescendo, estável ou declinando?
 -Em crescimento, muito popular no meio desenvolvedor.
&#x20;



\- Como esse banco se compara com seu principal concorrente?
-O MySQL ainda é uma ótima escolha para sites tradicionais e aplicações simples de leitura, porém o PostgreSQL, por ser mais complexo, é essencial em sistemas corporativos e aplicações com IA.

&#x20;



&#x20;



4.10) Qual seria um projeto ideal para usar este banco de dados? Descreva um cenário real:
-Sistemas financeiros que exigem alta precisão e segurança, para evitar problemas com os dados.
-Sistemas de Geolocalização: utilizam mapas com rastreamento, a extensão PostGIS é referência global para a manipulação desses tipos de dados, sejam terrestres ou espaciais.
-:Aplicativo de Mobilidade Urbana e Chamada de Corridas, estilo Uber. Quando o passageiro solicita viagem, ocorre uma consulta usando o PostGSI para pegar as coordenadas do passageiro e fazer uma busca por raio, listando os motoristas mais próximos sem sobrecarregar o sistema. Utiliza também a extensão para estimar o tempo de chegada com base em cálculos pela distância real e a velocidade média, áreas de risco, etc. Assim que o motorista cruza o limite do usuário que solicitou a corrida, o banco valida a entrada na área e notifica automaticamente o usuário. No final do dia, relatórios podem ser feito utilizando densidade de corridas por local e horário, identificando áreas que precisam de mais motoristas. 

&#x20;



&#x20;



###### **5. Pensamento Crítico e Reflexão**

5.1) Por que você acredita que Edgar F. Codd criou 12 princípios para um modelo relacional? O que isso mostra sobre a importância de padronização em bancos de dados?

-Edgar criou os princípios nos anos 80 para evitar "falso marketing" e proteger o modo relacional dos bancos de dados. Trouxe a ideia de utilizar álgebras em vez de ponteiros como nos sistemas anteriores, porém empresas começaram a nomear seus bancos tradicionais de "relacionais" apenas por mercado, sem oferecer realmente os benefícios que esse banco trás. Então, as regras foram publicadas para a verificação: se o db cumpre ou não os requisitos matemáticos e lógicos.
-A padronização garante que mudanças de infraestrutura não quebrem o sistema, visto que o banco pode ser consultado através da lógica, independente da forma que o computador armazenou os dados. O código de aplicação é sempre o mesmo, então o programador pode trabalhar em diversos sistemas sem precisar aprender a lógica nova do zero.


&#x20;



5.2) Você acredita que em 5 anos os bancos relacionais deixarão de ser populares? Por quê?

-Acredito que não, estão sempre em alta e passando por transformações. Continuará no mercado aquele que melhor se adaptar as tecnologias que vem surgindo. Mesmo que, supostamente, outra forma passe a existir, da mesma maneira que as linguagens de programação antigas permanecem no comércio bancário, acredito que grandes "empresas" não mudariam de sistema logo de cara.


&#x20;



5.3) Como você usaria o site DB-Engines para tomar uma decisão tecnológica em um projeto real? Quais informações você consideraria mais importantes?

-Utilizaria sim, como métrica. Sistemas muito mencionados têm maior relevância, mas é necessário ver se todas as menções são positivas, por exemplo. Se o banco se encaixa no projeto, se é eficiênte...




