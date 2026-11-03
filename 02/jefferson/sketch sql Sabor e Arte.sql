/*CREATE TABLE cliente (
    id_cliente SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cpf VARCHAR(14) NOT NULL UNIQUE,
    telefone VARCHAR(20) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    data_nascimento DATE
);

CREATE TABLE endereco (
    id_endereco SERIAL PRIMARY KEY,
    id_cliente INT NOT NULL,
    descricao VARCHAR(30) NOT NULL,
    logradouro VARCHAR(100) NOT NULL,
    numero VARCHAR(10) NOT NULL,
    complemento VARCHAR(50),
    bairro VARCHAR(50) NOT NULL,
    cidade VARCHAR(50) NOT NULL,
    uf VARCHAR(2) NOT NULL,
    cep VARCHAR(10) NOT NULL,
    FOREIGN KEY (id_cliente) REFERENCES cliente(id_cliente)
);

CREATE TABLE funcionario (
    codigo_funcional INT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    funcao VARCHAR(30) NOT NULL
);

CREATE TABLE mesa (
    numero_mesa INT PRIMARY KEY,
    capacidade INT NOT NULL CHECK (capacidade > 0)
);

CREATE TABLE cardapio (
    id_item SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    descricao VARCHAR(255),
    preco_atual DECIMAL(10,2) NOT NULL CHECK (preco_atual >= 0),
    disponivel BOOLEAN NOT NULL DEFAULT TRUE
);

CREATE TABLE adicional (
    id_adicional SERIAL PRIMARY KEY,
    nome VARCHAR(50) NOT NULL,
    preco DECIMAL(10,2) NOT NULL CHECK (preco >= 0)
);

CREATE TABLE produto_adicional (
    id_item INT NOT NULL,
    id_adicional INT NOT NULL,
    PRIMARY KEY (id_item, id_adicional),
    FOREIGN KEY (id_item) REFERENCES cardapio(id_item),
    FOREIGN KEY (id_adicional) REFERENCES adicional(id_adicional)
);

CREATE TABLE atendimento (
    id_atendimento SERIAL PRIMARY KEY,
    id_cliente INT NOT NULL,
    id_funcionario INT NOT NULL,
    numero_mesa INT NOT NULL,
    iniciou_em TIMESTAMP NOT NULL,
    situacao VARCHAR(20) NOT NULL,
    FOREIGN KEY (id_cliente) REFERENCES cliente(id_cliente),
    FOREIGN KEY (id_funcionario) REFERENCES funcionario(codigo_funcional),
    FOREIGN KEY (numero_mesa) REFERENCES mesa(numero_mesa)
);

CREATE TABLE pedido (
    id_pedido SERIAL PRIMARY KEY,
    id_cliente INT NOT NULL,
    id_atendimento INT NULL,
    data_hora_pedido TIMESTAMP NOT NULL,
    situacao VARCHAR(30) NOT NULL,
    valor_total DECIMAL(10,2) NOT NULL DEFAULT 0.00,
    FOREIGN KEY (id_cliente) REFERENCES cliente(id_cliente),
    FOREIGN KEY (id_atendimento) REFERENCES atendimento(id_atendimento)
);

CREATE TABLE item_pedido (
    id_item_pedido SERIAL PRIMARY KEY,
    id_pedido INT NOT NULL,
    id_item INT NOT NULL,
    quantidade INT NOT NULL CHECK (quantidade > 0),
    preco_unitario DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (id_pedido) REFERENCES pedido(id_pedido),
    FOREIGN KEY (id_item) REFERENCES cardapio(id_item)
);

CREATE TABLE item_pedido_adicional (
    id_item_pedido INT NOT NULL,
    id_adicional INT NOT NULL,
    preco_unitario DECIMAL(10,2) NOT NULL,
    PRIMARY KEY (id_item_pedido, id_adicional),
    FOREIGN KEY (id_item_pedido) REFERENCES item_pedido(id_item_pedido),
    FOREIGN KEY (id_adicional) REFERENCES adicional(id_adicional)
);

CREATE TABLE entrega (
    id_pedido INT PRIMARY KEY,
    id_endereco INT NOT NULL,
    id_funcionario INT NOT NULL,
    hora_saida TIMESTAMP,
    hora_entrega TIMESTAMP,
    situacao VARCHAR(30) NOT NULL,
    FOREIGN KEY (id_pedido) REFERENCES pedido(id_pedido),
    FOREIGN KEY (id_endereco) REFERENCES endereco(id_endereco),
    FOREIGN KEY (id_funcionario) REFERENCES funcionario(codigo_funcional)
);

CREATE TABLE forma_pagamento (
    id_forma_pagamento SERIAL PRIMARY KEY,
    nome VARCHAR(30) NOT NULL UNIQUE
);

CREATE TABLE pedido_pagamento (
    id_pedido INT NOT NULL,
    id_forma_pagamento INT NOT NULL,
    valor_pagamento DECIMAL(10,2) NOT NULL CHECK (valor_pagamento > 0),
    data_pagamento TIMESTAMP NOT NULL,
    PRIMARY KEY (id_pedido, id_forma_pagamento),
    FOREIGN KEY (id_pedido) REFERENCES pedido(id_pedido),
    FOREIGN KEY (id_forma_pagamento) REFERENCES forma_pagamento(id_forma_pagamento)
);

CREATE TABLE reserva (
    id_reserva SERIAL PRIMARY KEY,
    id_cliente INT NOT NULL,
    data_reserva DATE NOT NULL,
    hora_reserva TIME NOT NULL,
    quantidade_pessoas INT NOT NULL,
    situacao VARCHAR(20) NOT NULL,
    FOREIGN KEY (id_cliente) REFERENCES cliente(id_cliente)
);

CREATE TABLE reserva_mesa (
    id_reserva INT NOT NULL,
    numero_mesa INT NOT NULL,
    PRIMARY KEY (id_reserva, numero_mesa),
    FOREIGN KEY (id_reserva) REFERENCES reserva(id_reserva),
    FOREIGN KEY (numero_mesa) REFERENCES mesa(numero_mesa)
);*/