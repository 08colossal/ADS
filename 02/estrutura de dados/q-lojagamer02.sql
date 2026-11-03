SET search_path TO loja_gamer, public;

select count(*) from clientes where ativo = true;
select ativo, count(*) from clientes group by ativo;
select count(*) from clientes where estado = 'PR';

select ativo, SUM(estoque) as soma from produtos group by ativo;
select sum(pontos) as pontos from clientes where ativo = true;
select sum(valor_total) as total from pedidos where situacao = 'Pago';

select avg(preco) from produtos where ativo = true;
select avg(pontos) from clientes where ativo = false;

select min(data_pedido) as minimo, max(data_pedido) as maximo from pedidos;

select count(*) as qtd, estado from clientes group by estado;
select count(*) as qtd, cidade from clientes group by cidade order by cidade asc;
select count(*) as qtd, marca from produtos group by marca;
select count(*) as qtd, categoria, round(avg(preco),2) as media from produtos group by categoria order by media desc;
select nome from produtos where ativo = 'true' and nome like '%Gamer%';

-- consultas combinadas
select count(*) as qtd from produtos group by categoria order by qtd desc;
select sum(valor_total) as soma, forma_pagamento from pedidos where situacao = 'Pago' group by forma_pagamento order by soma desc;
select min(preco) as minimo, max(preco) as maximo, round(avg(preco),2) as media, marca from produtos group by marca order by marca asc;
select count(*) as qtd, round(avg(preco),2) as media from produtos where ativo = 'true' and nome like '%Gamer%' group by categoria order by media desc;
select situacao, forma_pagamento, count(*) as qtd_pedidos, round(avg(valor_total),2) as media, sum(valor_total) as soma_valores from pedidos
	group by situacao, forma_pagamento order by situacao asc, soma_valores desc;
-- group by situacao e pagamento -- mostre situacao forma qtd soma media

select * from produtos
select * from pedidos

 
/*---------------------------------------------------------*/

/*select * from clientes, pedidos, produtos;
select * from clientes where nome like 'Ana%';
select * from clientes where nome like '%Silva';
select * from clientes where nome like '%Costa%';
select * from clientes where email like '%gmail.com';
select * from clientes where cidade like 'São%';
select * from clientes where bairro like '%Jardim%';
select * from clientes where nome like '_a%';
select * from produtos where nome like 'Mouse%';
select * from produtos where nome like '%Gamer%';
select * from produtos where nome like '%RGB';
select * from produtos where no*/


/*------------------------------------------------------*/

/**
-- AULA: LIKE, ORDER BY e ALIAS (AS) - PostgreSQL
-- Cenário fictício: Loja Gamer / Tecnologia
-- Execute o arquivo inteiro no PostgreSQL (pgAdmin, DBeaver ou psql).
-- ATENÇÃO: este script apaga e recria APENAS as três tabelas do esquema loja_gamer.

CREATE SCHEMA IF NOT EXISTS loja_gamer;
SET search_path TO loja_gamer, public;

DROP TABLE IF EXISTS loja_gamer.pedidos, loja_gamer.produtos, loja_gamer.clientes CASCADE;

CREATE TABLE clientes (
  id SERIAL PRIMARY KEY,
  nome VARCHAR(100) NOT NULL,
  email VARCHAR(140) NOT NULL UNIQUE,
  cidade VARCHAR(80) NOT NULL,
  estado CHAR(2) NOT NULL,
  bairro VARCHAR(80) NOT NULL,
  ativo BOOLEAN NOT NULL DEFAULT TRUE,
  pontos INTEGER NOT NULL DEFAULT 0 CHECK (pontos >= 0),
  data_cadastro DATE NOT NULL
);

CREATE TABLE produtos (
  id SERIAL PRIMARY KEY,
  nome VARCHAR(120) NOT NULL,
  categoria VARCHAR(50) NOT NULL,
  marca VARCHAR(50) NOT NULL,
  descricao TEXT NOT NULL,
  preco NUMERIC(10,2) NOT NULL CHECK (preco >= 0),
  estoque INTEGER NOT NULL DEFAULT 0 CHECK (estoque >= 0),
  promocao BOOLEAN NOT NULL DEFAULT FALSE,
  ativo BOOLEAN NOT NULL DEFAULT TRUE,
  data_cadastro DATE NOT NULL
);

CREATE TABLE pedidos (
  id SERIAL PRIMARY KEY,
  codigo VARCHAR(20) NOT NULL UNIQUE,
  cliente_id INTEGER NOT NULL REFERENCES clientes(id),
  data_pedido DATE NOT NULL,
  forma_pagamento VARCHAR(40) NOT NULL,
  situacao VARCHAR(20) NOT NULL CHECK (situacao IN ('Pago', 'Pendente', 'Cancelado')),
  valor_total NUMERIC(10,2) NOT NULL CHECK (valor_total >= 0),
  desconto NUMERIC(10,2) NOT NULL DEFAULT 0 CHECK (desconto >= 0),
  observacao TEXT NOT NULL
);

-- 40 clientes, 50 produtos e 48 pedidos. Todos os dados são fictícios.

INSERT INTO clientes (nome, email, cidade, estado, bairro, ativo, pontos, data_cadastro) VALUES
  ('Ana Paula Martins', 'ana.paula.martins@gmail.com', 'Maringá', 'PR', 'Jardim América', TRUE, 95, '2024-02-04'),
  ('Ana Clara Souza', 'ana.clara.souza@outlook.com', 'Pato Branco', 'PR', 'Bairro Alto', TRUE, 232, '2024-04-17'),
  ('André Luiz Ribeiro', 'andre.luiz.ribeiro@email.com', 'Florianópolis', 'SC', 'São Cristóvão', TRUE, 369, '2024-06-29'),
  ('Antônio Silva', 'antonio.silva@gmail.com', 'Chapecó', 'SC', 'Centro', FALSE, 506, '2024-09-10'),
  ('Beatriz Costa', 'beatriz.costa@proton.me', 'Cascavel', 'PR', 'Jardim das Flores', TRUE, 643, '2024-11-22'),
  ('Bruno Almeida', 'bruno.almeida@gmail.com', 'Londrina', 'PR', 'Vila Nova', TRUE, 780, '2025-02-03'),
  ('Camila Nogueira', 'camila.nogueira@hotmail.com', 'Foz do Iguaçu', 'PR', 'Centro Cívico', TRUE, 917, '2025-04-17'),
  ('Carlos Eduardo Lopes', 'carlos.eduardo.lopes@gmail.com', 'Joinville', 'SC', 'Água Verde', TRUE, 1054, '2025-06-29'),
  ('Carolina Freitas', 'carolina.freitas@outlook.com', 'São José dos Pinhais', 'PR', 'Jardim América', TRUE, 1191, '2025-09-10'),
  ('Daniel Souza', 'daniel.souza@email.com', 'Toledo', 'PR', 'Bairro Alto', TRUE, 1328, '2025-11-22'),
  ('Daniela Moreira', 'daniela.moreira@gmail.com', 'Palotina', 'PR', 'São Cristóvão', FALSE, 1465, '2026-02-03'),
  ('Diego Martins', 'diego.martins@proton.me', 'São Paulo', 'SP', 'Centro', TRUE, 1602, '2026-04-17'),
  ('Eduarda Rocha', 'eduarda.rocha@gmail.com', 'Porto Alegre', 'RS', 'Jardim das Flores', TRUE, 89, '2026-06-29'),
  ('Elisa Monteiro', 'elisa.monteiro@hotmail.com', 'Curitiba', 'PR', 'Vila Nova', TRUE, 226, '2024-02-23'),
  ('Felipe Carvalho', 'felipe.carvalho@gmail.com', 'Maringá', 'PR', 'Centro Cívico', TRUE, 363, '2024-05-06'),
  ('Fernanda Lima', 'fernanda.lima@outlook.com', 'Pato Branco', 'PR', 'Água Verde', TRUE, 500, '2024-07-18'),
  ('Gabriel Oliveira', 'gabriel.oliveira@email.com', 'Florianópolis', 'SC', 'Jardim América', TRUE, 637, '2024-09-29'),
  ('Gabriela Souza', 'gabriela.souza@gmail.com', 'Chapecó', 'SC', 'Bairro Alto', FALSE, 774, '2024-12-11'),
  ('Gustavo Pereira', 'gustavo.pereira@proton.me', 'Cascavel', 'PR', 'São Cristóvão', TRUE, 911, '2025-02-22'),
  ('Helena Duarte', 'helena.duarte@gmail.com', 'Londrina', 'PR', 'Centro', TRUE, 1048, '2025-05-06'),
  ('Igor Santos', 'igor.santos@hotmail.com', 'Foz do Iguaçu', 'PR', 'Jardim das Flores', TRUE, 1185, '2025-07-18'),
  ('Isabela Fernandes', 'isabela.fernandes@gmail.com', 'Joinville', 'SC', 'Vila Nova', TRUE, 1322, '2025-09-29'),
  ('João Pedro Almeida', 'joao.pedro.almeida@outlook.com', 'São José dos Pinhais', 'PR', 'Centro Cívico', TRUE, 1459, '2025-12-11'),
  ('Júlia Marques', 'julia.marques@email.com', 'Toledo', 'PR', 'Água Verde', TRUE, 1596, '2026-02-22'),
  ('Larissa Costa', 'larissa.costa@gmail.com', 'Palotina', 'PR', 'Jardim América', FALSE, 83, '2026-05-06'),
  ('Lucas Andrade', 'lucas.andrade@proton.me', 'São Paulo', 'SP', 'Bairro Alto', TRUE, 220, '2026-07-18'),
  ('Luana Ribeiro', 'luana.ribeiro@gmail.com', 'Porto Alegre', 'RS', 'São Cristóvão', TRUE, 357, '2024-03-13'),
  ('Marcos Vinícius Silva', 'marcos.vinicius.silva@hotmail.com', 'Curitiba', 'PR', 'Centro', TRUE, 494, '2024-05-25'),
  ('Maria Clara Gomes', 'maria.clara.gomes@gmail.com', 'Maringá', 'PR', 'Jardim das Flores', TRUE, 631, '2024-08-06'),
  ('Mariana Teixeira', 'mariana.teixeira@outlook.com', 'Pato Branco', 'PR', 'Vila Nova', TRUE, 768, '2024-10-18'),
  ('Mateus Martins', 'mateus.martins@email.com', 'Florianópolis', 'SC', 'Centro Cívico', TRUE, 905, '2024-12-30'),
  ('Natália Ferreira', 'natalia.ferreira@gmail.com', 'Chapecó', 'SC', 'Água Verde', FALSE, 1042, '2025-03-13'),
  ('Pedro Henrique Lima', 'pedro.henrique.lima@proton.me', 'Cascavel', 'PR', 'Jardim América', TRUE, 1179, '2025-05-25'),
  ('Rafael Costa', 'rafael.costa@gmail.com', 'Londrina', 'PR', 'Bairro Alto', TRUE, 1316, '2025-08-06'),
  ('Renata Barros', 'renata.barros@hotmail.com', 'Foz do Iguaçu', 'PR', 'São Cristóvão', TRUE, 1453, '2025-10-18'),
  ('Sofia Almeida', 'sofia.almeida@gmail.com', 'Joinville', 'SC', 'Centro', TRUE, 1590, '2025-12-30'),
  ('Thiago Martins', 'thiago.martins@outlook.com', 'São José dos Pinhais', 'PR', 'Jardim das Flores', TRUE, 77, '2026-03-13'),
  ('Vitor Hugo Souza', 'vitor.hugo.souza@email.com', 'Toledo', 'PR', 'Vila Nova', TRUE, 214, '2026-05-25'),
  ('Marcela Silva', 'marcela.silva@gmail.com', 'Palotina', 'PR', 'Centro Cívico', FALSE, 351, '2026-08-06'),
  ('Ana Carolina Costa', 'ana.carolina.costa@proton.me', 'São Paulo', 'SP', 'Água Verde', TRUE, 488, '2024-04-01');

INSERT INTO produtos (nome, categoria, marca, descricao, preco, estoque, promocao, ativo, data_cadastro) VALUES
  ('Mouse Gamer Orion RGB', 'Periféricos', 'Orion', 'Mouse com iluminação RGB e sensor óptico', 129.9, 22, TRUE, TRUE, '2024-04-05'),
  ('Mouse Gamer Falcon Pro', 'Periféricos', 'Falcon', 'Mouse profissional com alta precisão', 219.9, 6, FALSE, TRUE, '2024-05-06'),
  ('Mouse Sem Fio Compact', 'Periféricos', 'NovaTech', 'Mouse sem fio para escritório', 79.9, 45, TRUE, TRUE, '2024-06-06'),
  ('Teclado Mecânico Aurora', 'Periféricos', 'Orion', 'Teclado com teclas mecânicas e cabo USB', 329.9, 11, FALSE, TRUE, '2024-07-07'),
  ('Teclado Mecânico Eclipse RGB', 'Periféricos', 'Nexa', 'Teclado com iluminação RGB ajustável', 449.9, 9, TRUE, TRUE, '2024-08-07'),
  ('Teclado Gamer Nitro', 'Periféricos', 'ThunderX', 'Teclado compacto para jogos', 159.9, 18, FALSE, TRUE, '2024-09-07'),
  ('Headset Gamer Thunder', 'Áudio', 'ThunderX', 'Headset com microfone e isolamento', 249.9, 13, TRUE, TRUE, '2024-10-08'),
  ('Headset Gamer Cloud', 'Áudio', 'Nexa', 'Headset leve para longas sessões', 349.9, 4, FALSE, TRUE, '2024-11-08'),
  ('Headset Bluetooth Wave', 'Áudio', 'NovaTech', 'Headset sem fio com Bluetooth', 189.9, 27, TRUE, TRUE, '2024-12-09'),
  ('Monitor Gamer 24 Polegadas', 'Monitores', 'Orion', 'Monitor Full HD com alta taxa de atualização', 899.9, 7, TRUE, TRUE, '2025-01-09'),
  ('Monitor Gamer 27 Polegadas', 'Monitores', 'Nexa', 'Monitor IPS para jogos', 1399.9, 3, FALSE, TRUE, '2025-02-09'),
  ('Monitor Ultrawide 29 Polegadas', 'Monitores', 'Vista', 'Monitor ultrawide para produtividade', 1799.9, 5, TRUE, TRUE, '2025-03-12'),
  ('Webcam Full HD Vision', 'Câmeras', 'Vista', 'Webcam com microfone embutido', 199.9, 34, FALSE, TRUE, '2025-04-12'),
  ('Webcam 4K Studio', 'Câmeras', 'Vista', 'Webcam profissional para transmissão', 749.9, 5, TRUE, TRUE, '2025-05-13'),
  ('Cadeira Gamer Titan', 'Móveis', 'ThunderX', 'Cadeira com ajuste de altura', 1199.9, 0, FALSE, TRUE, '2025-06-13'),
  ('Cadeira Gamer Comfort', 'Móveis', 'Nexa', 'Cadeira confortável para jogos', 999.9, 8, TRUE, TRUE, '2025-07-14'),
  ('Controle Sem Fio Pro', 'Games', 'Falcon', 'Controle sem fio com bateria', 279.9, 20, TRUE, TRUE, '2025-08-14'),
  ('Controle Gamer Dual', 'Games', 'Orion', 'Controle para computador e console', 189.9, 17, FALSE, TRUE, '2025-09-14'),
  ('SSD 500GB Velocity', 'Componentes', 'Velocity', 'Armazenamento SSD de alta velocidade', 249.9, 40, TRUE, TRUE, '2025-10-15'),
  ('SSD 1TB Lightning', 'Componentes', 'Velocity', 'Armazenamento de 1TB', 399.9, 16, FALSE, TRUE, '2025-11-15'),
  ('SSD 2TB Max', 'Componentes', 'Nexa', 'Armazenamento de 2TB', 799.9, 2, TRUE, TRUE, '2025-12-16'),
  ('Memória RAM 8GB DDR4', 'Componentes', 'NovaTech', 'Memória para computadores', 139.9, 23, FALSE, TRUE, '2026-01-16'),
  ('Memória RAM 16GB DDR4', 'Componentes', 'NovaTech', 'Memória DDR4 para desktops', 219.9, 14, TRUE, TRUE, '2026-02-16'),
  ('Memória RAM 32GB DDR5', 'Componentes', 'Orion', 'Memória de alto desempenho', 639.9, 6, FALSE, TRUE, '2026-03-19'),
  ('Placa de Vídeo RTX 4060', 'Componentes', 'Falcon', 'Placa de vídeo dedicada', 2199.9, 4, TRUE, TRUE, '2026-04-19'),
  ('Placa de Vídeo RTX 4070', 'Componentes', 'Falcon', 'Placa de vídeo para aplicações exigentes', 3899.9, 0, FALSE, FALSE, '2026-05-20'),
  ('Fonte 650W Bronze', 'Componentes', 'Volt', 'Fonte com certificação bronze', 399.9, 12, TRUE, TRUE, '2026-06-20'),
  ('Fonte 750W Gold', 'Componentes', 'Volt', 'Fonte com certificação gold', 599.9, 10, FALSE, TRUE, '2026-07-21'),
  ('Gabinete Gamer Crystal', 'Componentes', 'Crystal', 'Gabinete com vidro lateral', 429.9, 11, FALSE, TRUE, '2026-08-21'),
  ('Gabinete Gamer Shadow', 'Componentes', 'Crystal', 'Gabinete com excelente ventilação', 299.9, 25, TRUE, TRUE, '2024-04-14'),
  ('Kit Mouse e Teclado Basic', 'Kits', 'NovaTech', 'Kit para uso cotidiano', 109.9, 31, TRUE, TRUE, '2024-05-15'),
  ('Kit Streaming Creator', 'Kits', 'Vista', 'Kit para criação de conteúdo', 849.9, 4, FALSE, TRUE, '2024-06-15'),
  ('Microfone USB Podcast', 'Áudio', 'Vista', 'Microfone USB com suporte de mesa', 279.9, 8, TRUE, TRUE, '2024-07-16'),
  ('Microfone Condensador Studio', 'Áudio', 'Nexa', 'Microfone para gravações', 499.9, 3, FALSE, TRUE, '2024-08-16'),
  ('Suporte para Monitor Articulado', 'Acessórios', 'Nexa', 'Suporte com ajuste de altura', 189.9, 30, FALSE, TRUE, '2024-09-16'),
  ('Suporte para Notebook Alumínio', 'Acessórios', 'NovaTech', 'Suporte leve e dobrável', 89.9, 21, TRUE, TRUE, '2024-10-17'),
  ('Cabo HDMI 2 Metros', 'Acessórios', 'Volt', 'Cabo para monitores e televisão', 29.9, 80, TRUE, TRUE, '2024-11-17'),
  ('Cabo USB-C 1 Metro', 'Acessórios', 'Volt', 'Cabo USB-C para dados e carga', 39.9, 55, FALSE, TRUE, '2024-12-18'),
  ('Adaptador USB-C Multiportas', 'Acessórios', 'NovaTech', 'Adaptador USB-C com múltiplas conexões', 129.9, 7, TRUE, TRUE, '2025-01-18'),
  ('Hub USB 4 Portas', 'Acessórios', 'NovaTech', 'Expansor USB de quatro portas', 69.9, 3, FALSE, TRUE, '2025-02-18'),
  ('Roteador Wi-Fi 6', 'Redes', 'Velocity', 'Roteador sem fio para redes rápidas', 459.9, 10, TRUE, TRUE, '2025-03-21'),
  ('Notebook Gamer Storm 15', 'Notebooks', 'ThunderX', 'Notebook com placa gráfica dedicada', 5499.9, 5, FALSE, TRUE, '2025-04-21'),
  ('Notebook Office 14', 'Notebooks', 'NovaTech', 'Notebook leve para trabalho', 2899.9, 17, TRUE, TRUE, '2025-05-22'),
  ('Mochila para Notebook Urban', 'Acessórios', 'Nexa', 'Mochila com compartimento acolchoado', 159.9, 28, TRUE, TRUE, '2025-06-22'),
  ('Mousepad Gamer XL', 'Acessórios', 'Falcon', 'Mousepad de tamanho extra', 59.9, 39, FALSE, TRUE, '2025-07-23'),
  ('Mousepad Gamer RGB', 'Acessórios', 'Falcon', 'Mousepad com iluminação RGB', 119.9, 9, TRUE, TRUE, '2025-08-23'),
  ('Base Refrigerada para Notebook', 'Acessórios', 'Volt', 'Base com ventilação USB', 149.9, 13, FALSE, TRUE, '2025-09-23'),
  ('Carregador USB-C 65W', 'Acessórios', 'Volt', 'Carregador USB-C para notebook', 169.9, 8, TRUE, TRUE, '2025-10-24'),
  ('Caixa de Som Bluetooth Mini', 'Áudio', 'NovaTech', 'Caixa de som sem fio portátil', 99.9, 35, FALSE, TRUE, '2025-11-24'),
  ('Caixa de Som Gamer RGB', 'Áudio', 'Orion', 'Caixa de som com iluminação RGB', 229.9, 5, TRUE, FALSE, '2025-12-25');

INSERT INTO pedidos (codigo, cliente_id, data_pedido, forma_pagamento, situacao, valor_total, desconto, observacao) VALUES
  ('PED-2025-001', 10, '2025-07-10', 'PIX', 'Pago', 316.2, 0.0, 'Entrega expressa'),
  ('PED-2025-002', 17, '2025-12-17', 'Cartão de Crédito', 'Pago', 506.9, 0.0, 'Retirada na loja'),
  ('PED-2025-003', 24, '2025-05-24', 'Boleto', 'Pago', 626.5, 94, 'Presente de aniversário'),
  ('PED-2025-004', 31, '2025-10-07', 'Cartão de Débito', 'Pendente', 817.2, 0.0, 'Aguardando confirmação'),
  ('PED-2025-005', 38, '2025-03-14', 'PIX', 'Pago', 1007.9, 0.0, 'Entrega agendada'),
  ('PED-2025-006', 5, '2025-08-21', 'Transferência', 'Pago', 1127.5, 133, 'Solicitou nota fiscal'),
  ('PED-2025-007', 12, '2025-01-04', 'PIX', 'Pago', 1318.2, 0.0, 'Entrega no período da tarde'),
  ('PED-2025-008', 19, '2025-06-11', 'Cartão de Crédito', 'Pendente', 1508.9, 0.0, 'Sem observações'),
  ('PED-2025-009', 26, '2025-11-18', 'Boleto', 'Pago', 1628.5, 172, 'Cliente solicitou embalagem especial'),
  ('PED-2025-010', 33, '2025-04-25', 'Cartão de Débito', 'Pago', 1819.2, 0.0, 'Entrega por transportadora'),
  ('PED-2025-011', 40, '2025-09-08', 'PIX', 'Cancelado', 2009.9, 0.0, 'Entrega expressa'),
  ('PED-2025-012', 7, '2025-02-15', 'Transferência', 'Pendente', 2129.5, 211, 'Retirada na loja'),
  ('PED-2025-013', 14, '2025-07-22', 'PIX', 'Pago', 2320.2, 0.0, 'Presente de aniversário'),
  ('PED-2025-014', 21, '2025-12-05', 'Cartão de Crédito', 'Pago', 2510.9, 0.0, 'Aguardando confirmação'),
  ('PED-2025-015', 28, '2025-05-12', 'Boleto', 'Pago', 230.5, 60, 'Entrega agendada'),
  ('PED-2025-016', 35, '2025-10-19', 'Cartão de Débito', 'Pendente', 421.2, 0.0, 'Solicitou nota fiscal'),
  ('PED-2025-017', 2, '2025-03-26', 'PIX', 'Pago', 611.9, 0.0, 'Entrega no período da tarde'),
  ('PED-2025-018', 9, '2025-08-09', 'Transferência', 'Pago', 731.5, 99, 'Sem observações'),
  ('PED-2025-019', 16, '2025-01-16', 'PIX', 'Pago', 922.2, 0.0, 'Cliente solicitou embalagem especial'),
  ('PED-2025-020', 23, '2025-06-23', 'Cartão de Crédito', 'Pendente', 1112.9, 0.0, 'Entrega por transportadora'),
  ('PED-2025-021', 30, '2025-11-06', 'Boleto', 'Pago', 1232.5, 138, 'Entrega expressa'),
  ('PED-2025-022', 37, '2025-04-13', 'Cartão de Débito', 'Cancelado', 1423.2, 0.0, 'Retirada na loja'),
  ('PED-2025-023', 4, '2025-09-20', 'PIX', 'Pago', 1613.9, 0.0, 'Presente de aniversário'),
  ('PED-2025-024', 11, '2025-02-03', 'Transferência', 'Pendente', 1733.5, 177, 'Aguardando confirmação'),
  ('PED-2026-001', 18, '2026-04-10', 'PIX', 'Pago', 1924.2, 0.0, 'Entrega agendada'),
  ('PED-2026-002', 25, '2026-07-17', 'Cartão de Crédito', 'Pago', 2114.9, 0.0, 'Solicitou nota fiscal'),
  ('PED-2026-003', 32, '2026-10-15', 'Boleto', 'Pago', 2234.5, 216, 'Entrega no período da tarde'),
  ('PED-2026-004', 39, '2026-03-07', 'Cartão de Débito', 'Pendente', 2425.2, 0.0, 'Sem observações'),
  ('PED-2026-005', 6, '2026-06-14', 'PIX', 'Pago', 215.9, 0.0, 'Cliente solicitou embalagem especial'),
  ('PED-2026-006', 13, '2026-09-21', 'Transferência', 'Pago', 335.5, 65, 'Entrega por transportadora'),
  ('PED-2026-007', 20, '2026-02-04', 'PIX', 'Pago', 526.2, 0.0, 'Entrega expressa'),
  ('PED-2026-008', 27, '2026-05-11', 'Cartão de Crédito', 'Pendente', 716.9, 0.0, 'Retirada na loja'),
  ('PED-2026-009', 34, '2026-08-18', 'Boleto', 'Cancelado', 836.5, 104, 'Presente de aniversário'),
  ('PED-2026-010', 1, '2026-01-25', 'Cartão de Débito', 'Pago', 1027.2, 0.0, 'Aguardando confirmação'),
  ('PED-2026-011', 8, '2026-04-08', 'PIX', 'Pago', 1217.9, 0.0, 'Entrega agendada'),
  ('PED-2026-012', 15, '2026-07-15', 'Transferência', 'Pendente', 1337.5, 143, 'Solicitou nota fiscal'),
  ('PED-2026-013', 22, '2026-10-15', 'PIX', 'Pago', 1528.2, 0.0, 'Entrega no período da tarde'),
  ('PED-2026-014', 29, '2026-03-05', 'Cartão de Crédito', 'Pago', 1718.9, 0.0, 'Sem observações'),
  ('PED-2026-015', 36, '2026-06-12', 'Boleto', 'Pago', 1838.5, 182, 'Cliente solicitou embalagem especial'),
  ('PED-2026-016', 3, '2026-09-19', 'Cartão de Débito', 'Pendente', 2029.2, 0.0, 'Entrega por transportadora'),
  ('PED-2026-017', 10, '2026-02-26', 'PIX', 'Pago', 2219.9, 0.0, 'Entrega expressa'),
  ('PED-2026-018', 17, '2026-05-09', 'Transferência', 'Pago', 2339.5, 221, 'Retirada na loja'),
  ('PED-2026-019', 24, '2026-08-16', 'PIX', 'Pago', 2530.2, 0.0, 'Presente de aniversário'),
  ('PED-2026-020', 31, '2026-01-23', 'Cartão de Crédito', 'Cancelado', 320.9, 0.0, 'Aguardando confirmação'),
  ('PED-2026-021', 38, '2026-04-06', 'Boleto', 'Pago', 440.5, 70, 'Entrega agendada'),
  ('PED-2026-022', 5, '2026-07-13', 'Cartão de Débito', 'Pago', 631.2, 0.0, 'Solicitou nota fiscal'),
  ('PED-2026-023', 12, '2026-10-15', 'PIX', 'Pago', 821.9, 0.0, 'Entrega no período da tarde'),
  ('PED-2026-024', 19, '2026-03-03', 'Transferência', 'Pendente', 941.5, 109, 'Sem observações');

-- Verificação da carga: cada coluna deve mostrar o número indicado.
SELECT (SELECT COUNT(*) FROM clientes) AS total_clientes,
       (SELECT COUNT(*) FROM produtos) AS total_produtos,
       (SELECT COUNT(*) FROM pedidos) AS total_pedidos;

-- IMPORTANTE para novas abas/conexões no editor:
-- execute SET search_path TO loja_gamer, public;
-- ou utilize loja_gamer.clientes, loja_gamer.produtos, loja_gamer.pedidos.*/
